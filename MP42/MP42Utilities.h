//
//  MP42Utilities.h
//  MP42Foundation
//
//  Created by Damiano Galassi on 16/11/13.
//  Copyright (c) 2013 Damiano Galassi. All rights reserved.
//

#import "MP42MediaFormat.h"

NSString * StringFromTime(long long time, long timeScale);
MP42Duration TimeFromString(NSString *SMPTE_string, MP42Duration timeScale);

NSArray *supportedFileFormat();
BOOL isFileFormatSupported(NSString *fileExt);

BOOL isTrackMuxable(NSString * formatName);
BOOL trackNeedConversion(NSString * formatName);

int isHdVideo(uint64_t width, uint64_t height);
