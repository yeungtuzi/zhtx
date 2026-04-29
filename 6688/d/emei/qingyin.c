// Room: /d/emei/qingyinge.c 峨嵋派 清音阁
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "清音阁");
        set("long",
"清音阁素以“"GRN"双桥清音"NOR"”著称，它背依牛心岭而向五显岭，\n"
"山峦叠翠，阁下有双飞桥，分别飞跨黑龙江和白龙江，稍息亭中，\n"
"看远山暝暝，听近水潺潺，确有一种“起舞弄清影，何似在人间”\n"
"的意境。\n"
        );

        set("exits", ([
                "southdown" : __DIR__"shenshui",
		"eastup" : __DIR__"wannian",
                "westup" : __DIR__"gate",
               ]));
        setup();
        replace_program(ROOM);
}