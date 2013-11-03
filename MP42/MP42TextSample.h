//
//  SBTextSample.h
//  MP42
//
//  Created by Damiano Galassi on 01/11/13.
//  Copyright (c) 2013 Damiano Galassi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MP42MediaFormat.h"
#import "MP42Image.h"

@interface MP42TextSample : NSObject <NSCoding> {
    MP42Duration timestamp;
    MP42Image *image;
    NSString *title;
}

@property(readwrite, retain) NSString *title;
@property(readwrite, retain) MP42Image *image;
@property(readwrite) MP42Duration timestamp;

@end

