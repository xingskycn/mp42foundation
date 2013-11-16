//
//  MP42Utilities.m
//  MP42Foundation
//
//  Created by Damiano Galassi on 16/11/13.
//  Copyright (c) 2013 Damiano Galassi. All rights reserved.
//

#import "MP42Utilities.h"

NSString * SMPTEStringFromTime(long long time, long timeScale)
{
    NSString *SMPTE_string;
    int hour, minute, second, frame;
    long long result;

    result = time / timeScale; // second
    frame = (time % timeScale) / 10;

    second = result % 60;

    result = result / 60; // minute
    minute = result % 60;

    result = result / 60; // hour
    hour = result % 24;

    SMPTE_string = [NSString stringWithFormat:@"%d:%02d:%02d:%02d", hour, minute, second, frame]; // h:mm:ss:ff

    return SMPTE_string;
}

MP42Duration TimeFromSMPTEString(NSString* SMPTE_string, MP42Duration timeScale)
{
    int hour, minute, second, frame;
    MP42Duration timeval;

    sscanf([SMPTE_string UTF8String], "%d:%02d:%02d:%02d",&hour, &minute, &second, &frame);

    timeval = hour * 60 * 60 + minute * 60 + second;
	timeval = timeScale * timeval + ( frame * 10 );
    
    return timeval;
}

NSArray *supportedFileFormat()
{
    return [NSArray arrayWithObjects:@"scc", @"smi",  @"txt", @"m4v", @"mp4", @"m4a", @"m4a", @"mov", @"mts", @"m2ts",
            @"mkv", @"mka", @"mks", @"h264", @"264", @"idx", @"aac", @"ac3", @"srt", nil];
}

BOOL isFileFormatSupported(NSString * fileExt) {
    NSArray *supportedFormat = supportedFileFormat();

    for (NSString *type in supportedFormat)
        if ([fileExt caseInsensitiveCompare:type] == NSOrderedSame)
            return YES;

    return NO;
}

BOOL isTrackMuxable(NSString * formatName)
{
    NSArray* supportedFormats = [NSArray arrayWithObjects:MP42VideoFormatH264, MP42VideoFormatMPEG4Visual, MP42AudioFormatAAC, MP42AudioFormatALAC, MP42AudioFormatAC3, MP42AudioFormatDTS, MP42SubtitleFormatTx3g, MP42SubtitleFormatText, MP42ClosedCaptionFormatCEA608, MP42VideoFormatJPEG, MP42SubtitleFormatVobSub, nil];

    for (NSString* type in supportedFormats)
        if ([formatName isEqualToString:type])
            return YES;

    return NO;
}

BOOL trackNeedConversion(NSString * formatName) {
    NSArray* supportedConversionFormats = [NSArray arrayWithObjects:MP42AudioFormatVorbis, MP42AudioFormatFLAC, MP42AudioFormatMP3, MP42AudioFormatTrueHD, MP42SubtitleFormatSSA, MP42SubtitleFormatText, MP42SubtitleFormatPGS, nil];

    for (NSString* type in supportedConversionFormats)
        if ([formatName isEqualToString:type])
            return YES;

    return NO;
}

int isHdVideo(uint64_t width, uint64_t height)
{
    if ((width > 1280) || (height > 720))
        return 2;
    else if (((width >= 960) && (height >= 720)) || width >= 1280)
        return 1;

    return 0;
}
