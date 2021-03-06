/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_OS_IDL_WIREWRITER_H
#define YARP_OS_IDL_WIREWRITER_H

#include <yarp/conf/numeric.h>
#include <yarp/os/api.h>
#include <yarp/os/ConnectionWriter.h>
#include <yarp/os/idl/WireReader.h>
#include <yarp/os/idl/WirePortable.h>
#include <yarp/os/Vocab.h>
#include <yarp/os/Bottle.h>

#include <string>

namespace yarp {
    namespace os {
        namespace idl {
            class WireWriter;
        }
    }
}

/**
 *
 * IDL-friendly connection writer. Used by YARP IDL tools, not intended
 * for end-user.
 *
 */
class YARP_OS_API yarp::os::idl::WireWriter {
public:

    WireWriter(ConnectionWriter& writer);

    WireWriter(WireReader& reader);

    ~WireWriter();

    bool isNull() const;

    bool write(const WirePortable& obj) const;

    bool write(const yarp::os::PortWriter& obj) const;

    bool writeNested(const WirePortable& obj) const;

    bool writeNested(const yarp::os::PortWriter& obj) const;

    bool writeBool(bool x) const;

    bool writeI8(std::int8_t x) const;

    bool writeI16(std::int16_t x) const;

    bool writeI32(std::int32_t x) const;

    bool writeI64(std::int64_t x) const;

    bool writeFloat32(yarp::conf::float32_t x) const;

    bool writeFloat64(yarp::conf::float64_t x) const;

#ifndef YARP_NO_DEPRECATED // Since YARP 3.0.0
    YARP_DEPRECATED_MSG("Use writeI8 instead")
    bool writeByte(std::int8_t x) const { return writeI8(x); }

    YARP_DEPRECATED_MSG("Use writeFloat64 instead")
    bool writeDouble(double x) const { return writeFloat64(static_cast<yarp::conf::float64_t>(x)); }
#endif // YARP_NO_DEPRECATED

    bool writeVocab(std::int32_t x) const;

    bool isValid() const;

    bool isError() const;

    bool writeTag(const char *tag, int split, int len) const;

    bool writeString(const std::string& tag) const;

    bool writeBinary(const std::string& tag) const;

    bool writeListHeader(int len) const;

    bool writeListBegin(int tag, std::uint32_t len) const;

    bool writeSetBegin(int tag, std::uint32_t len) const;

    bool writeMapBegin(int tag, int tag2, std::uint32_t len) const;

    bool writeListEnd() const;

    bool writeSetEnd() const;

    bool writeMapEnd() const;

    bool writeOnewayResponse() const;

private:
    bool get_mode;
    YARP_SUPPRESS_DLL_INTERFACE_WARNING_ARG(std::string) get_string;
    bool get_is_vocab;
    mutable bool need_ok;
    ConnectionWriter& writer;
};

#endif // YARP_OS_IDL_WIREWRITER_H
