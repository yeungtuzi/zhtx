inherit ROOM;

void create ()
{
        set ("short", "纵横工作站");
        set ("long", 
@LONG
这里就是纵横天下大管家——道全的工作站。
LONG);
        set("exits", 
        ([
                "west" : "/d/wizard/wizard_room",
                        ]));

        set("valid_startroom", 1);
        set("no_fight", 1);
        replace_program(ROOM);
        setup();
}

