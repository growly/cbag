// SPDX-License-Identifier: BSD-3-Clause AND Apache-2.0
/*
Copyright (c) 2018, Regents of the University of California
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


Copyright 2019 Blue Cheetah Analog Design Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <iostream>
#include <string>

#include <fmt/core.h>

#include <cbag/logging/logging.h>
#include <cbag/oa/database.h>
#include <cbag/oa/read.h>
#include <cbag/schematic/cellview.h>

void write_cv_yaml(const char *lib_name, const char *cell_name, const char *view_name = "symbol",
                   const char *output = nullptr, const char *lib_file = "cds.lib") {
    std::string out_fname;
    if (output == nullptr)
        out_fname = fmt::format("{}.yaml", cell_name);
    else
        out_fname = output;

    cbagoa::database db(lib_file);
    auto cv = db.read_sch_cellview(lib_name, cell_name, view_name);

    cv.to_file(out_fname);
}

int main(int argc, char *argv[]) {
    switch (argc) {
    case 3:
        write_cv_yaml(argv[1], argv[2]);
        break;
    case 4:
        write_cv_yaml(argv[1], argv[2], argv[3]);
        break;
    case 5:
        write_cv_yaml(argv[1], argv[2], argv[3], argv[4]);
        break;
    case 6:
        write_cv_yaml(argv[1], argv[2], argv[3], argv[4], argv[5]);
        break;
    default:
        std::cout << "Usage: write_cv_yaml <lib_name> <cell_name> [<view_name> [<output> "
                     "[<cds_lib_fname>]]]"
                  << std::endl;
    }

    return 0;
}
