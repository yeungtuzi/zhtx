inherit ROOM;
void create()
{
 set("short", "古墓墓洞");
 set("long", @LONG
 这里是古墓派的墓洞，四周都是石壁，异常的黑暗，厅堂上并列
放着五口棺材(guancai?)，更显的阴森恐怖，旁边挂着一幅画(picture)
此外别无他物。
LONG
 );
set("item_desc", ([
 "picture" : "一幅古朴却洁净无比的画，画中一位女子，左手持剑，右手似乎掌心
向下，端的是英气逼人，美涣绝伦！另人观之有天神之感。画面绝无半点灰尘，
竟似有人每天打扫，难道这死人墓中竟有活人不成？
你看着看着，不禁看的呆了,双腿也好象软了一样,似乎便要荧荧下拜\n",
  "guancai?" : "这里是五口一模一样的大红棺材，给本就阴森可怖的大殿平填了
几分鬼气。\n",
]));
 setup();
}
void init()
{
        add_action("do_enter", "enter");
        add_action("do_juan","juan");
         add_action("do_kneel","kneel");
}
int do_enter(string arg)
{
object me;
me = this_player();
        if( !arg || arg=="" ) return 0;
 if( arg=="guancai1" ||arg=="guancai2"||arg=="guancai3")
 {
 message("vision","这个棺材里有尸体，还是不进去为妙。\n",me);

// environment(me), ({me}) );
  //              me->move(__DIR__"guancai1");
    //            message("vision",
 //me->name() + "从棺材里跳了出来。\n",
   //             environment(me), ({me}) );
 return 1;
}
 /*   if( arg=="guancai2" )
 {
 message("vision",
 me->name() + "缓缓推开棺盖，一纵身跳进棺材里边。\n", environment(me), ({me}) );
               me->move(__DIR__"guancai2");
                message("vision",
 me->name() + "从棺材里跳了出来，哇，好恐怖！\n",
                environment(me), ({me}) );
 return 1;
}*/
/*if( arg=="guancai3" )
{
 message("vision",
 me->name() + "缓缓推开棺盖，一纵身跳进棺材里边。\n",
 environment(me), ({me}) );
                me->move(__DIR__"guancai3");
                message("vision",
 me->name() + "从棺材里跳了出来，好象很兴奋。\n",
                environment(me), ({me}) );
 return 1;
}*/
if( arg=="guancai4" )
 {
 message("vision",
 me->name() + "缓缓推开棺盖，一纵身跳进棺材里边。\n",
 environment(me), ({me}) );                me->move(__DIR__"guancai4");
                message("vision",
 me->name() + "从棺材里跳了出来。\n",
                environment(me), ({me}) );
 return 1;
}
if( arg=="guancai5" )
 {
 message("vision",
 me->name() + "缓缓移开棺盖一角，一纵身跳进棺材里边。\n",
 environment(me), ({me}) );
                me->move(__DIR__"guancai5");
                message("vision",
 me->name() + "从棺材里跳了出来。\n",
                environment(me), ({me}) );
 return 1;
}
 }
int do_kneel(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return notify_fail("你要拜谁?\n");
                if( arg=="picture" ) {
             write(
             "你朝着那天人模样的女子拜了下去，正在站起的一瞬间，
       你抬起头，突然发现从这个角度，那女子的右手手心是朝着你的，
       手心中有个字，好象是“拳”，“卷”，？太暗了，你也看不清。\n"
             );
             this_player()->set_temp("marks/卷", 1);
             return 1;
       }
}
int do_juan(string arg)
{
        object me;
        me = this_player();
        if (me->query_temp("marks/卷") ) {
            message("vision", me->name() + "对着画做了些什么，你眼前一道白光
           ，伴随着叮呤呤的响声，一刹那，一切平静，人也不见了。\n",
                    environment(me), ({me}) );
            me->move(__DIR__"ceshi");
            tell_object(me,"忽然一阵旋晕，你好象被人给抓了过来！\n");
            message("vision", me->name() + "被小龙女的铃索卷了过来。\n",
                    environment(me), ({me}) );
            this_player()->set_temp("marks/卷", 0);
	  return 1;
        }
        else {
            write("你想干什么？!\n");
            return 1;
        }
}