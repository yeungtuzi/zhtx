//jiasha.c 辟邪剑法 150级到180级的剑谱
#include <ansi.h>
inherit ITEM;

void create()
{
     set_name(RED"破袈裟"NOR,({"jia sha","jiasha","book"}));
     if( clonep() )
              set_default_object(__FILE__);
       else {

              set("long",@LONG
这是一件破破烂烂的红色袈裟，上面密密麻麻写满了小字，你想仔细
去看清，却怎么也无法识别上面潦草的笔迹。看来是有什么秘密是的。
你可以去试着读它（ＲＥＡＤ）。
LONG);
              set("no_drop",1);
              set("no_get",1);
              set("value",0);
              set("no_give",1);
              }
     setup();
}
void init()
{
    add_action("do_read","read");
}

int do_read(string arg)
{
	object me,ob;
	int lv;
	// 2026-04-30: unused variable commented out
	// int i;
	me=this_player();
	if ((!arg)||(arg=="")||(!objectp(ob=present(arg,me))))
	return notify_fail("你想读什么？？\n");
	if ((arg=="book")
	||  (arg=="jia sha")
	||  (arg=="jiasha"))
	{
	   if (me->query_skill("caoshu",1)<120)
	      return notify_fail("这件袈裟上的字迹实在是太潦草了，你根本无法看明白。\n");
	   if (me->query_skill("pixie-sword",1)<100)
              return notify_fail("这上面说的武功实在是太精深了，你无法了解其中的精髓。\n");   
	   if (me->query_skill("pixie-sword",1)>181)
	      return notify_fail("你对这件袈裟上的内容已经完全明了，不需要再读了。\n");
	   lv=me->query_skill("caoshu");
	   me->add("sen",-(200-lv));
	   me->add("force",-10);
	   me->improve_skill("pixie-sword",(int)(lv/5+random(me->query("int"))));
	   message_vision("你正在专心研读破袈裟上的文字。\n",me);
	}
	return 1;
	
}