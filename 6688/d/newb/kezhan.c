///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

string* names = ({
         "/d/shaolin/obj/mala-doufu",
         "/d/shaolin/obj/bocai-fentiao",
         "/d/shaolin/obj/shanhu-baicai",
         "/d/shaolin/obj/liuli-qiezi",
});

void create()
{
        set("short", "悦来客栈");
        set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚，你
可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待着南腔北调
的客人。客店的主人据传是一位神秘的人物，他究竟是谁，有各种各样的猜测。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "north" : __DIR__"guangchang",
                  "south": __DIR__"kefang",
                ]));
                set("objects", ([
                                __DIR__"npc/waiter": 1,
                                "/d/shaolin/obj/qingshui-hulu" : 2,
                                                names[random(sizeof(names))]: 1,
                                                names[random(sizeof(names))]: 1,
                        ]));
        setup();
}



