//ROOM:/d/qiankun/entrance.c
//by masterall
//2003.6.30 

#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";

void create()
{
        set("short", HIM"乾坤教宝藏库入口"NOR);
        set("long", @LONG
                 再往前就是传说中乾坤教的宝藏库了，据说司空晓风经营数十年的积蓄
和收藏的神兵利器、武林秘笈都藏在这里，四周空荡荡的没有一个人把守，令
你大感诧异。在你面前的是一个黑漆漆的山洞，急速的气流不断的卷吸进去，
发出“呜呜”的回音，似乎有鬼神看守着这有去无回的藏宝要地。
LONG
        );

        set("exits", ([
                "north" : __DIR__"cave",
        ]));
        set("objects",([
                 __DIR__"npc/wraith2" : 1,
        ]));
        set("blocks/north","youming wraith");
        setup();
//replace_program(ROOM);
}


