//
//  MP42Metadata.h
//  Subler
//
//  Created by Damiano Galassi on 06/02/09.
//  Copyright 2009 Damiano Galassi. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MP42MediaFormat.h"

@interface MP42Metadata : NSObject <NSCoding, NSCopying> {
@private
    NSString                *presetName;
    NSMutableDictionary     *tagsDict;

    NSMutableArray          *artworks;
    
    NSArray                 *artworkThumbURLs;
    NSArray                 *artworkFullsizeURLs;
    NSArray                 *artworkProviderNames;
	
	NSString *ratingiTunesCode;

    uint8_t mediaKind;
    uint8_t contentRating;
    uint8_t hdVideo;
    uint8_t gapless;
    uint8_t podcast;

    BOOL isEdited;
    BOOL isArtworkEdited;
}

- (instancetype) initWithFileHandle:(MP42FileHandle)fileHandle;
- (instancetype) initWithFileURL:(NSURL *)URL;

- (NSArray *) availableMetadata;
- (NSArray *) writableMetadata;

- (NSArray *) availableGenres;

- (void) removeTagForKey:(NSString *)aKey;
- (BOOL) setTag:(id)value forKey:(NSString *)key;
- (BOOL) setMediaKindFromString:(NSString *)mediaKindString;
- (BOOL) setContentRatingFromString:(NSString *)contentRatingString;
- (BOOL) setArtworkFromFilePath:(NSString *)imageFilePath;

- (BOOL) writeMetadataWithFileHandle: (MP42FileHandle *) fileHandle;

- (BOOL) mergeMetadata: (MP42Metadata *) newMetadata;

@property(nonatomic, readonly) NSMutableDictionary *tagsDict;

@property(nonatomic, readwrite, retain) NSString   *presetName;

@property(nonatomic, readwrite, retain) NSMutableArray *artworks;

@property(nonatomic, readwrite, retain) NSArray    *artworkThumbURLs;
@property(nonatomic, readwrite, retain) NSArray    *artworkFullsizeURLs;
@property(nonatomic ,readwrite, retain) NSArray    *artworkProviderNames;

@property(nonatomic, readwrite) uint8_t    mediaKind;
@property(nonatomic, readwrite) uint8_t    contentRating;
@property(nonatomic, readwrite) uint8_t    hdVideo;
@property(nonatomic, readwrite) uint8_t    gapless;
@property(nonatomic, readwrite) uint8_t    podcast;
@property(nonatomic, readwrite) BOOL       isEdited;
@property(nonatomic, readwrite) BOOL       isArtworkEdited;

@end
