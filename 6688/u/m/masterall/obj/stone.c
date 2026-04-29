//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BLK"石头"NOR , ({ "stone" }) );
        set_weight(600);
        set("no_get",1);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_paimai",1);
        set("value",0);
        set("long", "一块黑乎乎得石头，也不知道搁在这里有多少年了。
上面长满了苔藓，但你隐隐的能够摸出一条裂缝，好像可以掰开(break)。\n");
        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "块");
        
}

void init()
{
       add_action("do_break","break");
}

int query_autoload() { return 1; }

int do_break()
{
         object me,wan,lu,cha,guo,wang,shi;
         int luck;
         wan=new("/d/moyu/obj/nineflower");
         lu=new("/d/qiankun/obj/nineflower");
         cha=new("/d/qiankun/obj/shenxiancha");
         guo=new("/d/qiankun/obj/wangyouguo");
         wang=new("/d/qiankun/obj/jincanwang");
         shi=new("/d/qiankun/obj/dogshit");
         me = this_player();
         luck = random(me->qurey_kar()) + random(me->qurey_vis());

         if( me->query("str")< 50 )
                return notify_fail("你臂力太低了，根本掰不动这块石头。\n");

         if( me->query("force")< 3000 )
                return notify_fail("你内力太低了，根本掰不动这块石头。\n");

         message_vision("$N凝聚真气，将全身的功力汇集于双臂，爆喝一声，那块石头立即零七八碎的裂成好几瓣。\n与此同时，$N居然发现其中暗藏着一样东西，黑暗中也看不清楚是什么，随手就把它拾了起来。\n",me);
         me->add("force",-1000);

         if( luck > 60 ){ 
                     wang->move(me);
                     wang->set("owner", me);
         }else if( luck > 50 && luck < 61){
                     lu->move(me);
         }else if( luck > 40 && luck < 51){
                     guo->move(me);
         }else if( luck > 35 && luck < 41){
                     cha->move(me);
         }else if( luck > 30 && luck < 36){
                     wan->move(me);
         }else {
                     shi->move(me);
         }
       destruct(this_object());
               return 1;

}

