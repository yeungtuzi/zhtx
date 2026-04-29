#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short", HIC"大雄宝殿"NOR);
        set ("long", 
@LONG
祥云缭绕，紫气氛氲，一看便非等闲居所。
LONG);
    set("objects", ([ /* sizeof() == 1 */
/*
         "/class/xiaoyao/qiushui" : 1,
          "/u/l/lucifer/npc/niumowang" : 1,
          "/u/l/lucifer/npc/dog" : 1,
*/
//      "/u/l/lucifer/npc/pangban" : 1,
//      "/u/l/lucifer/npc/liruohai" : 1,
//      "/u/l/lucifer/npc/langfanyun" : 1,
 ]));
        set("exits", 
        ([
                "j" : "/d/jingcheng/tamgch",
//                 "west" : "/d/wizard/wizard_room",
                        ]));

        set("valid_startroom", 1);
//          set("no_fight", 1);
        replace_program(ROOM);
        setup();
}

