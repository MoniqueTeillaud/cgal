
#ifndef CGAL_PROJECTION_SPHERE-TRAITS_3_H
#define CGAL_PROJECTION_SPHERE-TRAITS_3_H

#include <CGAL/number_utils_classes.h>
#include <CGAL/triangulation_assertions.h>
#include <CGAL/Kernel_traits.h>
#include <CGAL/Delaunay_triangulation_sphere_traits_2.h>
namespace CGAL{template<typename K>	
class Projection_sphere_traits_3;
			   
 template < typename K>
class Projected_point 
: public K::Point_3{
	
public:
	typedef typename K::Point_3 Base_point;
Projected_point()
	:Base_point(),_computed(false){}
	
Projected_point(const Base_point &p)
	:Base_point(p){compute_scale(p);}

Projected_point(double x, double y, double z)
	:Base_point(x,y,z){compute_scale(x,y,z);}
	
public:	
	bool _computed;	
	double _scale;
	
private:
	void compute_scale(double x, double y, double z){
		double tmp = x*x+y*y+z*z;
		if (tmp == 0 )
			_scale = 0;
	
		else
			_scale = 1/sqrt(tmp);
	}
	
	void compute_scale(const Base_point &p){
		return compute_scale(p.x(), p.y(), p.z());
	}
		
};

	
template < class K, class P, class Predicate_ >
class Traits_with_projection_adaptor {
public:
 typedef Predicate_ Predicate;
		
typedef typename P::Point_2     Point;
typedef typename K::Point_2     Base_point;
Traits_with_projection_adaptor(Base_point sphere, double radius):_radius(radius), _sphere(sphere){}
double _radius;
Base_point _sphere ;
	
  typedef typename Predicate::result_type result_type;
		
		
		
 result_type operator()(const Point& p0, const Point& p1)  {
	return Predicate(_sphere)(project(p0), project(p1));
 }
	
 result_type operator()(const Point& p0, const Point& p1, const Point& p2)  {
 return Predicate(_sphere)(project(p0), project(p1), project(p2));
 }
	
 result_type operator ()(const Point& p0, const Point& p1, const Point& p2, const Point& p3)  {
	return Predicate(_sphere)(project(p0), project(p1), project(p2), project(p3));
 }
	
 result_type operator()(const Point& p0, const Point& p1, const Point& p2, const Point& p3, const Point& p4)  {
	return Predicate(_sphere)(project(p0), project(p1), project(p2), project(p3), project(p4));
 }
	
private:
 Base_point project (const Point& p){
   double scale = _radius*p._scale;
	return Base_point(scale*p.x(), scale*p.y(), scale*p.z());
 }
};
	
	
template < class R >
class Projection_sphere_traits_3
: public R
{
public:
 double _radius;
 typedef Delaunay_triangulation_sphere_traits_2<R>                     Base;
 typedef typename Projected_point<R>::Projected_point                  Point_2;
 typedef typename R::Point_3							               Base_point;
 typedef typename R::Point_3                                           Weighted_point_2;
 typedef Projection_sphere_traits_3<R>                                 Self;
 typedef Point_2                                                       result_type;
		
typedef Traits_with_projection_adaptor<Self,Self,typename Base::Power_test_2>
      Power_test_2;
 typedef Traits_with_projection_adaptor<Base, Self,typename Base::Orientation_2> 
	  Orientation_2;
 typedef Traits_with_projection_adaptor<Base,Self, typename Base::Coradial_sphere_2 >
	  Coradial_sphere_2;
 typedef Traits_with_projection_adaptor<Base,Self,typename Base::Inside_cone_2 >
	Inside_cone_2;
typedef Traits_with_projection_adaptor<Base,Self,typename Base::Orientation_1 >
	Orientation_1;

	
 typedef boost::false_type  requires_test;
 void set_radius(double radius){
			_radius = radius;
		}
		
		
Projection_sphere_traits_3(const Base_point& sphere=Base_point(0,0,0));
		
Orientation_2
orientation_2_object()const
{return Orientation_2(_sphere, _radius);}
		
Orientation_1
orientation_1_object() const 
{return Orientation_1(_sphere, _radius);}
		
Power_test_2 
power_test_2_object() const
{  return Power_test_2(_sphere, _radius);}
		
Coradial_sphere_2
coradial_sphere_2_object() const
{return Coradial_sphere_2(_sphere, _radius);}
		
Inside_cone_2
inside_cone_2_object() const 
{return Inside_cone_2(_sphere, _radius);}
		
		
protected :
	Base_point _sphere;
		
	};
	
template < class R >
Projection_sphere_traits_3<R> ::
Projection_sphere_traits_3(const Base_point& sphere)
: _sphere(sphere)
{}
	
	
} //namespace CGAL

#endif	
			   



