// Room: /d/quanzhen/fengchang.c


inherit ROOM;
void create()
{
	set("short", "空地");
	set("long", @LONG
你走到了一片开阔的空地上，忽然有许多的蜜蜂在你的旁边飞来飞去，
原来在这里的旁边摆着许多的蜂箱，不知到是谁在这里养了这么多的
蜜蜂。
LONG
	);
        set("mi",5);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaolu2.c",
]));
        set("objects",([
      __DIR__"npc/bee.c" : 4,
      __DIR__"npc/beewang.c" : 1,
 ]));

	setup();

}

void init()
{
   add_action("do_search","search");
}                                   

int do_search()
{
  object me = this_player();
  object ob,obj; 
  int sen;    
  if( me->is_busy() )
  return notify_fail("你上一个动作还没有完成呢。\n");                       
  sen=me->query("sen");
  if(sen<30)                    
  return notify_fail("你无法集中精力找东西！\n");
  message_vision("$N开始不顾一切的使劲翻弄着蜂巢，希望能找到一些蜂王蜜\n",me);

  me->start_busy(2); 
  me->set("sen", sen-10); 
  call_out("end",3,me);
  return 1;
}  
                 
void end(object me)
{
 object ob,obj1,obj;
  obj=environment(me);
 switch(random(8)){                   
 case 0:
 case 1:  message_vision("$N惊出了一群蜜蜂.\n",me);
          obj1=new(__DIR__"npc/bee.c");
          obj1->move(environment(me));
          break;
 case 2:
 case 3:
 case 4:  message_vision("$N累了个半死，结果什么都没有找到。\n",me);
          break;  
 case 5:  if(obj->query("mi") != 0)
          {
          ob=new(__DIR__"npc/obj/fengwmi.c");
          ob->move(me);
          obj->set("mi",obj->query("mi")-1); 
          message_vision("$N找到了一些蜂王蜜，放在$N的身上。\n",me);
          break;
          }         
 default: message_vision("$N累了个半死，结果什么都没有找到。\n",me);
          break;
 }
}        
