//
//  MP42File.h
//  Subler
//
//  Created by Damiano Galassi on 31/01/09.
//  Copyright 2009 Damiano Galassi. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MP42Track.h"
#import "MP42VideoTrack.h"
#import "MP42AudioTrack.h"
#import "MP42SubtitleTrack.h"
#import "MP42ClosedCaptionTrack.h"
#import "MP42ChapterTrack.h"
#import "MP42Metadata.h"

#import "MP42MediaFormat.h"

extern NSString * const MP4264BitData;
extern NSString * const MP4264BitTime;
extern NSString * const MP42GenerateChaptersPreviewTrack;
extern NSString * const MP42CustomChaptersPreviewTrack;
extern NSString * const MP42OrganizeAlternateGroups;

typedef enum MP42Status : NSInteger {
    MP42StatusLoaded = 0,
    MP42StatusReading,
    MP42StatusWriting
} MP42Status;

@protocol MP42FileDelegate <NSObject>
@optional
- (void)progressStatus:(CGFloat)progress;
- (void)saveDidEnd:(id)sender;
@end

@class MP42Muxer;

@interface MP42File : NSObject <NSCoding> {
    MP42FileHandle   _fileHandle;
    NSURL           *_fileURL;

    id <MP42FileDelegate> _delegate;

    NSMutableArray      *_tracksToBeDeleted;
    NSMutableDictionary *_importers;

    BOOL        _hasFileRepresentation;

    MP42Status  _status;
    BOOL        _cancelled;

    NSMutableArray  *_tracks;
    MP42Metadata    *_metadata;
    MP42Muxer       *_muxer;
}

@property(nonatomic, readwrite, assign) id <MP42FileDelegate> delegate;

@property(nonatomic, readonly) NSURL *URL;
@property(nonatomic, readonly) MP42Metadata *metadata;
@property(nonatomic, readonly) NSArray *tracks;

@property(nonatomic, readonly) BOOL hasFileRepresentation;
@property(nonatomic, readonly) NSUInteger duration;
@property(nonatomic, readonly) uint64_t dataSize;

- (instancetype)initWithDelegate:(id <MP42FileDelegate>)del;
- (instancetype)initWithExistingFile:(NSURL *)URL andDelegate:(id <MP42FileDelegate>)del;

- (NSUInteger)tracksCount;
- (MP42Track *)trackAtIndex:(NSUInteger)index;
- (MP42Track *)trackWithTrackID:(NSUInteger)trackId;
- (NSArray *)tracksWithMediaType:(NSString *)mediaType;

- (void)addTrack:(MP42Track *)track;

- (void)removeTrackAtIndex:(NSUInteger)index;
- (void)removeTracksAtIndexes:(NSIndexSet *)indexes;
- (void)moveTrackAtIndex:(NSUInteger)index toIndex:(NSUInteger)newIndex;

- (MP42ChapterTrack *)chapters;
/** 
 * Create a set of alternate group the way iTunes and Apple devices want:
 * one alternate group for sound, one for subtitles, a disabled photo-jpeg track,
 * a disabled chapter track, and a video track with no alternate group
 */
- (void)organizeAlternateGroups;

- (BOOL)optimize;

- (BOOL)writeToUrl:(NSURL *)url withAttributes:(NSDictionary *)attributes error:(NSError **)outError;
- (BOOL)updateMP4FileWithAttributes:(NSDictionary *)attributes error:(NSError **)outError;
- (void)cancel;

@end
