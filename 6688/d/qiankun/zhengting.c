// zhengting.c 
// by Masterall
 
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "乾坤教正厅");
        set("long", @LONG
    这里就是乾坤教的正厅了，黄金色的屋子，黄金色的墙，黄金色的地，黄金色的屋
顶。屋子里每样东西都是黄金色的。绝对是黄金色的，和纯金完全一样的颜色。绝对完
全一样。因为这屋子的四壁和顶都镀上了一层纯金，地上铺的是金砖。屋子里每一样东
西都是黄金所铸，甚至连桌椅都是，连窗慢都是用金丝编成的。一个人正坐在用纯金铸
成的椅子上，椅子虽然冰冷坚硬，他坐在上面却显得很舒服。旁边有两列人规规矩矩的
垂手站立，满屋的金壁辉煌好像和他们全无关系，但每个人的举手投足，炯炯的目光，
俨然都是武林中的一流高手。 
LONG
        );
 
        set("exits", ([
                "south" : __DIR__"shibanlu1",
        ]));
        set("objects", ([
//   __DIR__"npc/master" : 1, 
                "/u/z/zephyr/master" : 1,
                 __DIR__"npc/jiaotu" : 6,
 ]));
        setup(); 
        replace_program(ROOM);
}

