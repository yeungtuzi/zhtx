// chengroom.c

inherit ROOM;
void search_cabinet(object me);
void create()
{
        set("short", "成不忧的卧室");
        set("long", @LONG
这里就是华山剑宗长老成不忧的卧室所在。屋里面很朴素的
样子，除了一个大衣柜和一张大桌之外没什么东西了。桌子上面
还摊着一叠白纸，白纸上似乎写着什么东西，墨迹还没干。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"zhongting",
]));

        set("objects", ([
                CLASS_D("huashan") + "/chengbuyou" : 1]));
         set("item_desc",([
               "白纸" : "这是一叠白纸，上面还有写印记是的，应该是写字时过于用力留下的痕迹。
旁边还有一点炭粉，或许可以用一下？\n",
               "paper" : "这是一叠白纸，上面还有写印记是的，应该是写字时过于用力留下的痕迹。
旁边还有一点炭粉，或许可以用一下？\n",
               "大衣柜":"这个大衣柜好象没有锁，只是虚掩着，但是主人在屋里，不好就这样翻吧。\n",
               "cabinet":"这个大衣柜好象没有锁，只是虚掩着，但是主人在屋里，不好就这样翻吧。\n",  
        ]));
        set("trigger",3);
        setup();
}


void init()
{
	add_action("do_smear","smear");
	add_action("do_search","search");
}
int do_smear(string arg)
{
   	object me,ob;

   	me = this_player();

   	if (!arg||arg=="")
   		return notify_fail("你要往白纸上摸什么东西？\n");
   	if (arg=="dust")
   	{
   	if (query("have_map"))	
   	    return notify_fail("这里已经没有炭粉了。\n");
   	else    
   	{
   		message_vision("你仔细地刮了一小撮炭粉，轻轻抹去最上面一张纸上，纸上便现出了花纹。\n",this_player(),this_player());
                message_vision("你仔细一看，原来是一幅地图，地图上面画地竟然是.........\n",this_player(),this_player());
	        ob=new(__DIR__"obj/map");
       	        ob->move(this_player());
	        set("have_map",1);
        }
        }
        return 1;
}
int do_search(string arg)
{
      object me,obj,room;
      me=this_player();
      room=environment(me);
      if (!arg||arg=="")
      return notify_fail("你想打开什么？\n");
      if (arg=="cabinet"||arg=="大衣柜")
      {
     	if (objectp(present("cheng buyou",environment(me))))
          	 {return notify_fail("主人还在屋里面，就这么乱动别人的东西，不好吧？\n");}
           else 
      if (me->is_busy())
      {
      	message_vision("你上一个动作还没完成，无法展开搜索。\n",me,me);
      	return 1;
      }
        else
           {
             message_vision("你悄悄打开了大衣柜，想从里面翻出点什么。\n",me,me);
             call_out("search_cabinet",5,me);
             me->start_busy(5);
           }
        }
        return 1;
  }
void search_cabinet(object me)
{
    object yaoshi,room;
    me=this_player();
    room=environment(me);
    if (!query("trigger")) 
        {
         message_vision("你什么也没找到。\n",me,me);
         return;
         }
    if (random(6))
    {   
        add("trigger",-1);
    	message_vision("你什么也没找到。\n",me,me);
    }
    else
    {
    message_vision("你找到了一把金黄色的钥匙。\n",me,me);
    yaoshi=new(__DIR__"obj/key");
    yaoshi->move(me);
    delete("trigger");
    }
    return;
}
