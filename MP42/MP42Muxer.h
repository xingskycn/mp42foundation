//
//  MP42Muxer.h
//  Subler
//
//  Created by Damiano Galassi on 30/06/10.
//  Copyright 2010 Damiano Galassi. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "mp4v2.h"
#import "MP42Logging.h"

@class MP42Track;

@protocol MP42MuxerDelegate
- (void)progressStatus:(CGFloat)progress;
@end

@interface MP42Muxer : NSObject {
@private
    MP4FileHandle    _fileHandle;

    id <MP42MuxerDelegate>  _delegate;
    id <MP42Logging>        _logger;

    NSMutableArray *_workingTracks;
    int32_t         _cancelled;
}

- (instancetype)initWithFileHandle:(MP4FileHandle)fileHandle delegate:(id <MP42MuxerDelegate>)del logger:(id <MP42Logging>)logger;

- (BOOL)canAddTrack:(MP42Track *)track;
- (void)addTrack:(MP42Track *)track;

- (BOOL)setup:(NSError **)outError;
- (void)work;
- (void)cancel;

@end
