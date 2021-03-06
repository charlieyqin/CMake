/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmCPackFreeBSDGenerator_h
#define cmCPackFreeBSDGenerator_h

#include <cmConfigure.h>

#include "cmCPackArchiveGenerator.h"
#include "cmCPackGenerator.h"

class cmGeneratedFileStream;

/** \class cmCPackFreeBSDGenerator
 * \brief A generator for FreeBSD package files (TXZ with a manifest)
 *
 */
class cmCPackFreeBSDGenerator : public cmCPackArchiveGenerator
{
public:
  cmCPackTypeMacro(cmCPackFreeBSDGenerator, cmCPackArchiveGenerator);
  /**
   * Construct generator
   */
  cmCPackFreeBSDGenerator();
  ~cmCPackFreeBSDGenerator() CM_OVERRIDE;

  int InitializeInternal() CM_OVERRIDE;
  int PackageFiles() CM_OVERRIDE;

protected:
  const char* GetOutputExtension() CM_OVERRIDE { return ".txz"; }

  std::string var_lookup(const char* var_name);
  void write_manifest_fields(cmGeneratedFileStream&);
};

#endif
