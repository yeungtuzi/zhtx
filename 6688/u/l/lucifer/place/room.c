inherit ROOM;

void create ()
{
        set ("short", "菜鸟之家");
        set ("long", 
@LONG
这里就是传说中的菜鸟————一点红的窝。
LONG);
        set("exits", 
        ([
                "west" : "/d/wizard/wizard_room",
                 "1":"/d/xanadu/lou1",
                 "2":"/d/xanadu/lou2",
                 "3":"/d/xanadu/lou3",
                  "4":"/d/xanadu/lou4",
                 "5":"/d/xanadu/lou5",
                 "6":"/d/xanadu/lou6",
                 "7":"/d/xanadu/lou7",
                "8":"/d/xanadu/lou8",
                 "9":"/d/xanadu/lou9",
                "up"  : "/d/xanadu/xukong",
                        ]));

        set("valid_startroom", 1);
        set("no_fight", 1);
        replace_program(ROOM);
        setup();
}




