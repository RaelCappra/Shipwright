#pragma once

#include "Resource.h"
#include "ResourceFactoryBinary.h"
#include "ResourceFactoryXML.h"
#include "soh/resource/type/AudioSoundFont.h"

namespace SOH {
class ResourceFactoryBinaryAudioSoundFontV2 : public Ship::ResourceFactoryBinary {
  public:
    std::shared_ptr<Ship::IResource> ReadResource(std::shared_ptr<Ship::File> file) override;
};

class ResourceFactoryXMLSoundFontV0 : public Ship::ResourceFactoryXML {
  public:
    std::shared_ptr<Ship::IResource> ReadResource(std::shared_ptr<Ship::File> file) override;
    static int8_t MediumStrToInt(const char* str);
    static int8_t CachePolicyToInt(const char* str);

  private:
    void ParseDrums(AudioSoundFont* soundFont, tinyxml2::XMLElement* element);
    void ParseInstruments(AudioSoundFont* soundFont, tinyxml2::XMLElement* element);
    void ParseSfxTable(AudioSoundFont* soundFont, tinyxml2::XMLElement* element);
    std::vector<AdsrEnvelope> ParseEnvelopes(AudioSoundFont* soundFont, tinyxml2::XMLElement* element,
                                             unsigned int* count);
};
} // namespace SOH
