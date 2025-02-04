#ifndef __INTEGRATE_HPP__
#define __INTEGRATE_HPP__

#include "spatial.hpp"
#include <cuda_runtime.h>
#include <cstdlib>
#include <cuda_runtime_api.h>
#include <device_atomic_functions.h>
#include <thrust/sort.h>

/*
 * Struct of device ptrs to hold the neighbor indices, prefix sums, and count of neighbors
 */ 
struct neighborList {
  int *neighbors;
  int *offsets;
  int *counts;
};

/* Cubic Spline Family of Approximating Kernels */ 
__host__ __device__ float cubicSpline(float distance, float smooth_radius);
__host__ __device__ float gradCubicSpline(float distance, float smooth_radius);
__host__ __device__ float laplacianCubicSpline(float distance, float smooth_radius);

__host__ void initOffsetTable();
__host__ neighborList *initNeighborList(uint32_t *list_size, uint32_t n_particles);

/* Host function to call search kernel and approximate forces for each particle */
__host__ void neighborSearch(
  neighborList *list,
  particleContainer *d_objs_,
  uint32_t *list_size, 
  Lookup *d_lookup_,
  uint32_t n_partitions,
  uint32_t n_particles,
  uint32_t containerCount[3],
  float h
);

/* Verlet integration passes */
__global__ void firstVerletKernel(particleContainer *d_objs_, uint32_t n_particles);
__global__ void secondVerletKernel(particleContainer *d_objs_, uint32_t n_particles);

#endif // __INTEGRATE_HPP__
