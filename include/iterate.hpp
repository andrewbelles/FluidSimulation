#ifndef __ITERATE_HPP__
#define __ITERATE_HPP__

#include "spatial.hpp"
#include "boundary.hpp"
#include "integrate.hpp"

__host__ void particleIterator(
  float *average_neighbor_count,
  spatialLookupTable *d_lookup_,
  particleContainer *d_particleContainer_,
  uint32_t *neighbors,
  uint32_t *neighbor_offset,
  uint32_t list_size,
  float **u_positions,
  float **u_densities,
  std::vector<float> container,
  uint32_t n_particles,
  uint32_t n_partitions, 
  const float h
);

#endif // __ITERATE_HPP__
