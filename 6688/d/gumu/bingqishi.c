// Room: /u/cuer/emei/houshan2.c

inherit ROOM;     

int do_sou();  
void end(object);

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这里是古墓中的一个小洞，中神通王重阳当时常把义
军的武器藏在这儿，以避免不必要的麻烦。现在这儿仍还
有许多兵器，不过大多数都上锈了，搜(sou)一下也许能搜到好
的兵器、

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mudao7",
]));
 	 
     set("shen",random(20));
	setup();
	
}



void init()
{         
   add_action("do_sou","sou");
}                                   

int do_sou()
{
  object me = this_player();
  object ob ; 
  int kee;    
  if( me->is_busy() )
  return notify_fail("你上一个动作还没有完成呢。\n");                       
  kee=me->query("kee");
  if(kee<50)                    
  return notify_fail("你无法集中力量查看！\n");
  if(me->query_temp("found_time")>=4)
   return notify_fail("不要太贪心啊!\n");

  message_vision("$N开始查看这里的一兵一器，希望能找到一把刀剑什么的。\n",me);
  me->start_busy(2); 
  me->set("kee", kee-30); 
  call_out("end",3,me);
  return 1;
}  
                 
void end(object me)
{
 object ob;              
 object obj = environment(me);
 switch(random(10)){
 case 2:  if(obj->query("shen") != 0)
          {ob=new(__DIR__"obj/tiejia");
          obj->set("shen",obj->query("shen")-1);
          ob->move(me);
          message_vision("$N找到了一副铁甲，放在$N的身上。\n",me);
          me->add_temp("found_time",1);
          break;                            
          }
 case 1:  if(obj->query("shen") !=0)
          {
          ob=new(__DIR__"obj/changbian");
          ob->move(me);
          message_vision("$N找到了一条长鞭，放在$N的身上。\n",me);
          me->add_temp("found_time",1);
          break;
          } 
 case 0:  if(obj->query("shen") !=0)
          {
          message_vision("$N找到一把长剑，放在$N的身上。\n",me);
          ob=new(__DIR__"obj/changjian");
          ob->move(me);
          break;
          me->add_temp("found_time",1);
          } 
 case 3:  if(obj->query("shen") !=0)
          {
          ob=new(__DIR__"obj/toukui");
          ob->move(me);
          message_vision("$N找到了一个头盔，放在$N的身上。\n",me);
          me->add_temp("found_time",1);
          break;
          }
case 4:   if(obj->query("shen") !=0)
          {
          ob=new("/obj/weapon/gangdao");
          ob->move(me);
          message_vision("$N找到了一柄钢刀，放在$N的身上。\n",me);
          me->add_temp("found_time",1);
          break;
          } 
case 5:   if(obj->query("shen") !=0)
          {
          ob=new("obj/weapon/glaive");
          ob->move(me);
          message_vision("$N找到了一柄鬼头刀，放在$N的身上。\n",me);
          me->add_temp("found_time",1);
          break;
          } 
case 6:   if(obj->query("shen") !=0)
          {
          ob=new("obj/weapon/yinqiang");
          ob->move(me);
          message_vision("$N找到了一柄亮银枪，放在$N的身上。\n",me);
          me->add_temp("found_time",1);
          break;
          } 
 

 default: message_vision("$N累了个半死，结果什么都没有找到。\n",me);
          break;          
 }
}

