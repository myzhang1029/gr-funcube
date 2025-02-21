/*
 * Copyright 2025 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(fcdpp_control.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(77898ac6ca84b335bc16fd4ed41a3067)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/funcube/fcdpp_control.h>
// pydoc.h is automatically generated in the build directory
#include <fcdpp_control_pydoc.h>

void bind_fcdpp_control(py::module& m)
{

    using fcdpp_control = gr::funcube::fcdpp_control;


    py::class_<fcdpp_control, gr::block, gr::basic_block, std::shared_ptr<fcdpp_control>>(
        m, "fcdpp_control", D(fcdpp_control))

        .def(py::init(&fcdpp_control::make), D(fcdpp_control, make))

        .def("set_freq",&fcdpp_control::set_freq,
            py::arg("freq"),
            D(fcdpp_control,set_freq)
        )

        .def("set_lna",&fcdpp_control::set_lna,
            py::arg("gain"),
            D(fcdpp_control,set_lna)
        )

        .def("set_mixer_gain",&fcdpp_control::set_mixer_gain,
            py::arg("gain"),
            D(fcdpp_control,set_mixer_gain)
        )

        .def("set_if_gain",&fcdpp_control::set_if_gain,
            py::arg("gain"),
            D(fcdpp_control,set_if_gain)
        );
}
