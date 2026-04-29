///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", HIW"乱石堆"NOR);
        set("long", @LONG
想不到岛上如此荒凉，只有一些大块的岩石，在海浪的拍击
下发出阵阵巨响。不过你突然发现岩石之间有一个洞，好像可以
钻进去。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"satan2",
                  "enter": __DIR__"hole",
                ]));
                set("outdoors", "newbie");

                setup();
}

int valid_leave(object me, string dir)
{
                int exp, i;
                object *inv;
                exp=me->query("combat_exp");
                if(dir == "enter") {
                if ( exp < 50000 )
                return notify_fail("你的经验不够，就别去了吧。\n");
           inv = all_inventory(me);
                        for( i=0;i<sizeof(inv);i++) {
                              if( inv[i]->is_character() )
                               return notify_fail("背人进去？不用吧。\n");
                }
                }
         return ::valid_leave(me, dir);
}
