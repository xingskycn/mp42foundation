//
//  MP42Ratings.h
//  Subler
//
//  Created by Douglas Stebila on 2013-06-02.
//
//

#import <Foundation/Foundation.h>

@interface MP42Ratings : NSObject {
	NSMutableArray *ratingsDictionary;
	NSMutableArray *ratings;
	NSMutableArray *iTunesCodes;
}

@property(readonly) NSArray *ratings;
@property(readonly) NSArray *iTunesCodes;

+ (MP42Ratings *) defaultManager;

- (void)updateRatingsCountry;
- (NSArray *) ratingsCountries;

- (NSUInteger) unknownIndex;
- (NSUInteger) ratingIndexForiTunesCode:(NSString *)aiTunesCode;
- (NSUInteger) ratingIndexForiTunesCountry:(NSString *)aCountry media:(NSString *)aMedia ratingString:(NSString *)aRatingString;

@end
