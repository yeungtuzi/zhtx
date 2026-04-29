// Room: /open/hihi/woshi1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"卧室"NOR);
	set("long", @LONG
这里是林平之的起居之地,可能是因为父亲的失踪,林平之要管理镖局的大
小事务,没有多少时间来整理房间,所以整个房间比较乱.在房子的西边墙上,挂
着一把很好看的武士剑,靠近北面床边的地方,有一个小小的书桌.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"houyuan",
	]));
	set("shrot", "卧室");
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
	  "书桌" : "这个书桌上有一个做工精致的笔架,十分惹人可爱.桌上
有一叠新的"+WHT"白纸"NOR+"，是主人用来临摹字帖用的。\n",
	]));

	setup();
	
	}
void init()
	{
        add_action("do_take", "take");
	}




int do_take(string arg)
{     
       object paper;
       object me;

       paper=new(__DIR__"obj/paper");
     
        me = this_player();
    if ( !arg || ( arg != "paper" ) ) return notify_fail("你要拿什么？\n");
       else if ( random((int)me->query("kar")) < 20 )
      { write("随便拿别人的东西不好吧，要拿也得挑个好时机啊。\n");
        return 1;}
      else if((int)query("paper_trigger")>=1) 
	return notify_fail("书桌上的白纸已经被别人拿光了。\n");
      else { 
	  message_vision("$N偷偷摸摸地从书桌上拿走一叠白纸.\n",me);
          paper->move(me);
	  add("paper_trigger",1);   
          return 1;
       }
 
}
