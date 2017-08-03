#if !defined(MODULES_OPTION_CHECK) && !defined(MODULES_INSTANTIATION)

#ifndef COMM_H
#define COMM_H
#include <types.h>
#include <system.h>
#include <binning.h>

class Comm {

protected:
  System* system;

  T_X_FLOAT comm_depth;

public:
  Comm(System* s, T_X_FLOAT comm_depth);
  virtual ~Comm();
  virtual void init();

  // Move particles which left local domain
  virtual void exchange();

  // Exchange ghost particles
  virtual void exchange_halo();

  // Update ghost particles
  virtual void update_halo();

  // Reverse communication of forces
  virtual void update_force();

  // Do a sum reduction over floats
  virtual void reduce_float(T_FLOAT* values, T_INT N);

  // Do a sum reduction over integers
  virtual void reduce_int(T_INT* values, T_INT N);

  // Do a max reduction over floats
  virtual void reduce_max_float(T_FLOAT* values, T_INT N);

  // Do a max reduction over integers
  virtual void reduce_max_int(T_INT* values, T_INT N);

  // Do a min reduction over floats
  virtual void reduce_min_float(T_FLOAT* values, T_INT N);

  // Do a min reduction over integers
  virtual void reduce_min_int(T_INT* values, T_INT N);

  // Do an inclusive scan over integers
  virtual void scan_int(T_INT* values, T_INT N);

  // Do a sum reduction over floats with weights
  virtual void weighted_reduce_float(T_FLOAT* values, T_INT* weight, T_INT N);

  // Create a processor grid
  virtual void create_domain_decomposition();

  // Get Processor rank
  virtual int process_rank();

  // Get number of processors
  virtual int num_processes();

  // Exit with error message
  virtual void error(const char *);

  // Get class name
  virtual const char* name();
};


#include<modules_comm.h>

#endif
#endif
