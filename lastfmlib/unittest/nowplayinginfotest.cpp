#include <gtest/gtest.h>

#include "lastfmlib/nowplayinginfo.h"

#include <iostream>

using std::string;

TEST(NowPlaingInfoTest, GetPostDataUtf8)
{
    NowPlayingInfo info("The Artist", "Trackname");
    info.setAlbum("An Album");
    info.setTrackLength(42);
    info.setTrackNr(4);

    EXPECT_EQ(string("&a=The+Artist&t=Trackname&b=An+Album&l=42&n=4&m="), info.getPostData());

    info.setMusicBrainzId("31e7b30b-f960-408f-908b-c8e277308eab");
    EXPECT_EQ(string("&a=The+Artist&t=Trackname&b=An+Album&l=42&n=4&m=31e7b30b-f960-408f-908b-c8e277308eab"), info.getPostData());
}

TEST(NowPlaingInfoTest, GetPostDataWidechar)
{
    NowPlayingInfo info(L"The Artist", L"Trackname");
    info.setAlbum(L"An Album");
    info.setTrackLength(42);
    info.setTrackNr(4);

    EXPECT_EQ(string("&a=The+Artist&t=Trackname&b=An+Album&l=42&n=4&m="), info.getPostData());

    info.setMusicBrainzId(L"31e7b30b-f960-408f-908b-c8e277308eab");
    EXPECT_EQ(string("&a=The+Artist&t=Trackname&b=An+Album&l=42&n=4&m=31e7b30b-f960-408f-908b-c8e277308eab"), info.getPostData());
}
