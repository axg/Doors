//
//  WorldModel.h
//  Doors
//
//  Created by Mathias Kegelmann on 10/7/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "DoorsDirections.h"
#import "DoorLocator.h"

@class WorldModel;

// I contain a list of DoorLocators of the doors I toggle
@interface DoorKnob : NSObject {
    WorldModel *worldModel;
    NSArray *doorLocators;
}
- (id)initWithWorldModel:(WorldModel *)aModel andDoorLocators:(NSArray *)aDoorLocatorArray;
- (void)toggle;
@end


@interface WorldModel : NSObject {
    BOOL horizontalDoorsOpen[3][2];
    BOOL verticalDoorsOpen[2][3];
    DoorKnob *doorKnobs[3][3];
    DoorsCoordinates playerPosition;
}

@property DoorsCoordinates playerPosition;

// invalid (x,y) implies false
- (BOOL)isHorizontalDoorOpenAtX:(int)x andY:(int)y;
- (BOOL)isHorizontalDoorOpen:(DoorsDoorCoordinates)doorCoordinates;
- (BOOL)isVerticalDoorOpenAtX:(int)x andY:(int)y;
- (BOOL)isVerticalDoorOpen:(DoorsDoorCoordinates)doorCoordinates;

- (void)openAllDoors;
- (void)closeHorizontalDoorAtX:(int)x andY:(int)y;
- (void)closeVerticalDoorAtX:(int)x andY:(int)y;

- (void)setDoorKnobAtX:(int)x andY:(int)y withDoors:(NSArray *)aDoorLocatorArray;

- (void)operateDoorKnob;
- (BOOL)moveInDirection:(Class)direction;
- (BOOL)playerAtTargetPosition;

@end


@interface WorldModel (private) 

- (BOOL)directionImpliesHorizontalDoor:(Class)direction;
- (DoorsDoorCoordinates) doorCoordinatesAt:(DoorsCoordinates)position andDirection:(Class)direction;
- (void)toggleDoor:(DoorLocator *)doorLocator;
- (BOOL)canMoveFrom:(DoorsCoordinates)position inDirection:(Class)direction;
- (void)operateDoorKnobAtX:(int)x andY:(int)y;

@end
