//
//  SBTextSample.h
//  MP42
//
//  Created by Damiano Galassi on 01/11/13.
//  Copyright (c) 2013 Damiano Galassi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MP42MediaFormat.h"

@interface MP42TextSample : NSObject <NSCoding> {
    MP42Duration timestamp;
    NSString *title;
}

@property(readwrite, retain) NSString *title;
@property(readwrite) MP42Duration timestamp;

@end

