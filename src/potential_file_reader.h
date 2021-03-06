/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Contributing authors: Richard Berger (Temple U)
------------------------------------------------------------------------- */

#ifndef LMP_POTENTIAL_FILE_READER_H
#define LMP_POTENTIAL_FILE_READER_H

#include <string>

#include "pointers.h"
#include "tokenizer.h"
#include "text_file_reader.h"

namespace LAMMPS_NS
{
  class PotentialFileReader : protected Pointers {
  protected:
    TextFileReader * reader;
    std::string filename;
    std::string filetype;

    TextFileReader * open_potential(const std::string& path);

  public:
    PotentialFileReader(class LAMMPS *lmp, const std::string &filename, const std::string &potential_name);
    virtual ~PotentialFileReader();

    void ignore_comments(bool value);

    void skip_line();
    char * next_line(int nparams = 0);
    void next_dvector(double * list, int n);
    ValueTokenizer next_values(int nparams, const std::string & separators = TOKENIZER_DEFAULT_SEPARATORS);

    // convenience functions
    double next_double();
    int    next_int();
    tagint next_tagint();
    bigint next_bigint();
    std::string next_string();
  };

} // namespace LAMMPS_NS

#endif
