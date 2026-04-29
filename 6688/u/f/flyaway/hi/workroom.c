//changan city
// [lsg 2000/11/16]
inherit ROOM;

void create ()
{
        set ("short", "杨柳岸");
        set ("long", @LONG


                  闲人免进


LONG);
        set("exits", 
        ([ //sizeof() == 2
                "down" : "/d/wizard/wizard_room",
                        ]));
        set("objects", 
        ([
//                  "/obj/wiz/rack" : 1,
        ]));

        set("valid_startroom", 1);
        set("no_fight", 1);
        replace_program(ROOM);
        setup();
}



