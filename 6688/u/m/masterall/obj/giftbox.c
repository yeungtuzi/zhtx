//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"新"+HIG"手"+HIY"礼盒"NOR , ({ "gift box", "box" }) );
        set_weight(600);
        set("no_get",1);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_paimai",1);
        set("value",0);
        set("long", HIM"这是一个精美的礼盒，是纵横天下II巫巫们为鼓励新手而特别发放的礼盒。\n上面用七彩的丝带包扎着，也不知道里面有些什么东西，还不打开(Open)看看？\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "个");
        
}
void init()
{
        add_action("open_box","open");
}


int open_box(string arg)
{
       object me,ob;
       int luck;

       if( !this_object()->id(arg) ) return 0;

       me = this_player();
       ob = this_object();
       luck = random(8);

       if( ob->query("owner") != me )
                return notify_fail("这个新手礼盒不是你的！\n");

       message_vision( HIG"$N轻轻把礼盒上的丝带拉开，只见……！\n"NOR,me);
       message("system",HIW "\n一道绚丽的礼花冲向天空，爆出了七彩的光芒！！\n
"+HIR"&&      &&      && "+HIY"&&&&&&&&&& "+HIG"&         "+HIC"      &&&    "+HIB"     &&      "+HIM"&&&         &&& "+HIW"&&&&&&&&&&
"+HIR" &      &&      &  "+HIY"&          "+HIG"&         "+HIC"  &&     &&  "+HIB"  &      &   "+HIM"&& &       & && "+HIW"&
"+HIR" &&    &&&&    &&  "+HIY"&          "+HIG"&         "+HIC" &&        & "+HIB" &        &  "+HIM"&&  &     &  && "+HIW"&
"+HIR"  &    &  &    &   "+HIY"&&&&&&&&&& "+HIG"&         "+HIC"&&           "+HIB"&&        && "+HIM"&&   &   &   && "+HIW"&&&&&&&&&&
"+HIR"  &&  &&  &&  &&   "+HIY"&          "+HIG"&         "+HIC"&&           "+HIB"&&        && "+HIM"&&    & &    && "+HIW"&
"+HIR"   &  &    &  &    "+HIY"&          "+HIG"&         "+HIC" &&          "+HIB" &        &  "+HIM"&&     &     && "+HIW"&
"+HIR"   &&&&    &&&&    "+HIY"&          "+HIG"&         "+HIC"  &&     &&  "+HIB"  &      &   "+HIM"&&     &&    && "+HIW"&
"+HIR"    &&      &&     "+HIY"&&&&&&&&&& "+HIG"&&&&&&&&& "+HIC"     &&&     "+HIB"     &&      "+HIM"&&     &&    && "+HIW"&&&&&&&&&&\n\n\n"NOR,users() );
       message("system",HIC "\n【新手使者】姬良(Ji liang)：欢迎"+me->name()+"加入纵横天下II的大家庭！ \n"NOR,users() );
       message("system",HIY "\n【新手使者】姬良(Ji liang)：请诸位大侠一定要对"+me->name()+"多多帮助！ \n\n"NOR,users() );


       if (luck == 0)
       {
       me->add("combat_exp", 80000);
       me->add("potential", 60000);
       tell_object(me,HIC"恭喜你获得了八万经验值，六万潜能的奖励！\n"NOR);
       } else if (luck == 1)
       {
       me->add("faith", 5000);
       me->add("wlshw", 3);
       tell_object(me,HIC"恭喜你获得了五千师门忠诚度，三点武林声望的奖励！\n"NOR);
       } else if (luck == 2)
       {
       me->add("int", 2);
       me->add("con", 2);
       tell_object(me,HIC"恭喜你获得了二点先天悟性，二点先天体质的奖励！\n"NOR);
       }else  if (luck == 3)
       {
       me->add("per", 2);
       me->add("dex", 2);
       tell_object(me,HIC"恭喜你获得了二点先天魅力，二点先天身法的奖励！\n"NOR);
       }else  if (luck == 4)
       {
       me->add("kar", 2);
       me->add("spi", 2);
       tell_object(me,HIC"恭喜你获得了二点先天福缘，二点先天灵性的奖励！\n"NOR);
       }else  if (luck == 5)
       {
       me->add("bln", 2);
       me->add("msc", 2);
       tell_object(me,HIC"恭喜你获得了二点先天平衡，二点先天臂力的奖励！\n"NOR);
       }
       else
       {
       me->add("vis", 2);
       me->add("wil", 2);
       tell_object(me,HIC"恭喜你获得了二点先天意志，二点先天远见的奖励！\n"NOR);
       }

       destruct(this_object());
        return 1;
}



