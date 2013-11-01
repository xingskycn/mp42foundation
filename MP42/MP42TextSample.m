//
//  SBTextSample.m
//  MP42
//
//  Created by Damiano Galassi on 01/11/13.
//  Copyright (c) 2013 Damiano Galassi. All rights reserved.
//

#import "MP42TextSample.h"

@implementation MP42TextSample

-(NSComparisonResult)compare:(MP42TextSample *)otherObject
{
    MP42Duration otherTimestamp = [otherObject timestamp];

    if (timestamp < otherTimestamp)
        return NSOrderedAscending;
    else if (timestamp > otherTimestamp)
        return NSOrderedDescending;

    return NSOrderedSame;
}

-(void) dealloc
{
    [title release];
    [super dealloc];
}

@synthesize timestamp;
@synthesize title;

- (void)encodeWithCoder:(NSCoder *)coder
{
    [coder encodeInt64:timestamp forKey:@"timestamp"];
    [coder encodeObject:title forKey:@"title"];
}

- (id)initWithCoder:(NSCoder *)decoder
{
    self = [super init];

    timestamp = [decoder decodeInt64ForKey:@"timestamp"];
    title = [[decoder decodeObjectForKey:@"title"] retain];

    return self;
}

@end
