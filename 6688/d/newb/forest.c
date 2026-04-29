///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", CYN"森林边"NOR);
        set("long", @LONG
这儿往北远远可以看见有一大片森林，一眼望去，无边无际。有几条小路指向北方，
听说有很多人到这里面打猎。旁边站着一个红光满面的老头，看起来是看守这片森林
的。旁边还树着一块木牌(board)。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "northeast" : __DIR__"forest1",
                  "northwest" : __DIR__"forest3",
                  "south" : __DIR__"ssroad2",
                ]));

                set("objects", ([ /* sizeof() == 1 */
                  __DIR__"npc/forestguard" : 1,
                ]));

                set("item_desc", ([
                                 "board": "\n 严禁无限制狩猎！！\n"]));

        setup();
}


