/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBSplineInterpolator.h"
#include "../../include/obj/NiBSplineData.h"
#include "../../include/obj/NiBSplineBasisData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBSplineInterpolator::TYPE("NiBSplineInterpolator", &NI_B_SPLINE_INTERPOLATOR_PARENT::TypeConst() );

NiBSplineInterpolator::NiBSplineInterpolator() NI_B_SPLINE_INTERPOLATOR_CONSTRUCT {}

NiBSplineInterpolator::~NiBSplineInterpolator() {}

void NiBSplineInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBSplineInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBSplineInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBSplineInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBSplineInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBSplineInterpolator::GetType() const {
	return TYPE;
};

float NiBSplineInterpolator::GetStartTime() const {
	return startTime;
}

void NiBSplineInterpolator::SetStartTime( float value ) {
	startTime = value;
}

float NiBSplineInterpolator::GetStopTime() const {
	return stopTime;
}

void NiBSplineInterpolator::SetStopTime( float value ) {
	stopTime = value;
}

Ref<NiBSplineData > NiBSplineInterpolator::GetSplineData() const {
	return splineData;
}

void NiBSplineInterpolator::SetSplineData( Ref<NiBSplineData > value ) {
	splineData = value;
}

Ref<NiBSplineBasisData > NiBSplineInterpolator::GetBasisData() const {
	return basisData;
}

void NiBSplineInterpolator::SetBasisData( Ref<NiBSplineBasisData > value ) {
	basisData = value;
}
/*********************************************************************
Simple b-spline curve algorithm

Copyright 1994 by Keith Vertanen (vertankd@cda.mrs.umn.edu)

Released to the public domain (your mileage may vary)

Found at: Programmers Heaven (www.programmersheaven.com/zone3/cat415/6660.htm)
Modified by: Theo 
- reformat and convert doubles to floats
- removed point structure in favor of arbitrary sized float array
**********************************************************************/
static void copy_floats(float* dest, float *src, int l)
{
   for (int i=0; i<l; ++i)
      dest[i] = src[i];
}

// calculate the blending value
static float blend(int k, int t, int *u, float v)  
{
   float value;
   if (t==1) {			// base case for the recursion
      value = ((u[k]<=v) && (v<u[k+1])) ? 1.0f : 0.0f;
   } else {
      if ((u[k+t-1]==u[k]) && (u[k+t]==u[k+1]))  // check for divide by zero
         value = 0;
      else if (u[k+t-1]==u[k]) // if a term's denominator is zero,use just the other
         value = (u[k+t] - v) / (u[k+t] - u[k+1]) * blend(k+1, t-1, u, v);
      else if (u[k+t]==u[k+1])
         value = (v - u[k]) / (u[k+t-1] - u[k]) * blend(k, t-1, u, v);
      else
         value = (v - u[k]) / (u[k+t-1] - u[k]) * blend(k, t-1, u, v) +
         (u[k+t] - v) / (u[k+t] - u[k+1]) * blend(k+1, t-1, u, v);
   }
   return value;
}

// figure out the knots
static void compute_intervals(int *u, int n, int t)
{
   for (int j=0; j<=n+t; j++) {
      if (j<t)
         u[j]=0;
      else if ((t<=j) && (j<=n))
         u[j]=j-t+1;
      else if (j>n)
         u[j]=n-t+2;  // if n-t=-2 then we're screwed, everything goes to 0
   }
}

static void compute_point(int *u, int n, int t, float v, int l, float *control, float *output)
{
   // initialize the variables that will hold our output
   for (int j=0; j<l; j++)
      output[j] = 0;
   for (int k=0; k<=n; k++) {
      float temp = blend(k,t,u,v);  // same blend is used for each dimension coordinate
      for (int j=0; j<l; j++)
         output[j] = output[j] + control[k*l + j] * temp;
   }
}

/*********************************************************************
bspline(int n, int t, int l, float *control, float *output, int num_output)

Parameters:
n          - the number of control points minus 1
t          - the degree of the polynomial plus 1
l          - size of control and output float vector block
control    - control point array made up of float structure
output     - array in which the calculate spline points are to be put
num_output - how many points on the spline are to be calculated

Pre-conditions:
n+2>t  (no curve results if n+2<=t)
control array contains the number of points specified by n
output array is the proper size to hold num_output point structures

control and output vectors must be contiguous float arrays

**********************************************************************/
void NiBSplineInterpolator::bspline(int n, int t, int l, float *control, float *output, int num_output)
{
   float *calc = new float[l];
   int *u = new int[n+t+1];
   compute_intervals(u, n, t);

   float increment=(float)(n-t+2)/(num_output-1);  // how much parameter goes up each time
   float interval=0;
   for (int output_index=0; output_index<num_output-1; output_index++) {
      compute_point(u, n, t, interval, l, control, calc);
      copy_floats(&output[output_index*l], calc, l);
      interval=interval+increment;  // increment our parameter
   }
   copy_floats(&output[(num_output-1)*l], &control[n*l], l); // put in the last points
   delete [] u;
   delete [] calc;
}

const Type & NiBSplineInterpolator::TypeConst() {
	return TYPE;
}
