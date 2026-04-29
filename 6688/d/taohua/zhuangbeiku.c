// Room: /d/new_taohua/zhuangbeiku.c

inherit ROOM;

void create()
{
	set("short", "装备库");
	set("long", @LONG
这屋由不剥皮的松木搭成。屋外攀满香藤，进屋后顿感一阵清凉。屋
内有一排箱子，均未上锁。箱内不知装着什么。      
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  

            "north": __DIR__"yaopinfang",
 
          ]));

 set("item_desc", ([
                "箱子": "一口箱子可以打开(open)\n",
                "box":"一口箱子可以打开(open)\n",
           ]));  
          setup();
 }

void reset()
{
     if( random(20) > 16 )
                set("havejia",1);
}
 void init()
{
        add_action("do_open","open");
}
int do_open(string arg)
{ object zhi,me;
  me=this_player(); 
     if ( (random(20)>18) && (int)me->query_skill("qimen-bagua",1)>71 && query("havejia") )
  {
  zhi=new(__DIR__"obj/ruanwei-jia"); 

  zhi->move(me);

  write( "\n你发现箱子内有一套甲，看看左右没人，顺手抄进自己的口袋。\n");
  delete("havejia");
  return 1;
  }
  write("箱子里什么都没有。\n");  
  return 1;
}
    





