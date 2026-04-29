//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"腊八粥"NOR , ({ "laba zhou", "zhou" }) );
        set_weight(600);
        set("value",0);
        set("long", HIY"这碗粥蒸气上冒，兀自在一个个气泡从粥底钻将上来，
一碗粥尽作深绿之色，瞧上去说不出的诡异。粥中之物菜不像菜，草不像草，有些
似是切成细粒的树根，有些似是压成扁片的木薯，药气极浓。群雄均知，毒物大都
呈青绿之色，这一碗粥深绿如此，只映得人面俱碧，药气刺鼻，其毒可知。\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "碗");
        
}

void init()
{
       add_action("do_drink","drink");
}

int do_drink()
{
         object me,ob,ob1;
         int luck;
         me = this_player();
         ob = this_object();

         luck = random(100);

         if( ob->query("owner") != me )
                return notify_fail("这碗腊八粥又不是你要来的，怎么这么馋嘴！？！？\n"); 

         message_vision(HIG"$N看着这碗诡异的腊八粥，心中食欲全无，几欲作呕，但碍于岛主的面子，还是硬着头皮喝了下去。\n"NOR,me);
         tell_object(me,HIY"你只觉药气刺鼻，入口却甜甜的并不难吃，顷刻间便喝了个碗底朝天。\n"NOR);

         if( luck > 90 ){ 
                     me->add("wlshw",50);
         tell_object(me,HIC"\n二位岛主满意的冲你点了点头，说道：“阁下既然有如此胆识，不愧为中原武林的杰出人物！”\n"NOR);
         tell_object(me,HIC"\n你的武林声望增加了"+HIR"50"+HIC"点！！\n"NOR);

         }else if( luck > 80 && luck < 91){
                     me->add("max_force",500); 
         tell_object(me,HIY"你觉得顿时体内真气翻涌，气冲丹田，一股热流流遍全身，\n陡然间你发现自己的内功造诣提高不少。\n"NOR);

         }else if( luck > 60 && luck < 81){
         tell_object(me,HIB"你慨叹一声，想到自己纵横江湖数年，大风大浪都闯过来了，\n难道还要栽倒在这小小一碗腊八粥上吗？\n顿时百感交集，只觉天地之间，已无自己所惧之事！\n"NOR);
                     me->add("cor",10); 
                     me->add("cps",10); 

         }else if( luck > 40 && luck < 61){
         tell_object(me,HIR"你突然觉得小腹一阵阵绞痛，一股阴气侵入了你的七经八脉，\n顿时你疼得满地打滚，上下翻飞，足足折腾了老半天！\n剧痛过后你突然发现自己身轻如燕，即便是走在钢丝上也可如履平地！！\n"NOR);
                     me->add("dex",15); 
                     me->add("bln",15); 

         }else if( luck > 10 && luck < 41){
         tell_object(me,HIM"你猛然间感到一股无名的力量牵扯着你，刹那间脸形已经痛苦得扭曲起来，\n这种感觉持续了良久，你才渐渐恢复了正常，\n突然发觉自己身轻体健，容光焕发，好像一下子年轻了好几岁！\n"NOR);
                     me->add("per",10); 
                     me->add("mud_age",-5*86400); 
                     if( me->query("mud_age") < 1){me->set("mud_age",1); }
         }else {
        tell_object(me,HIW"你这碗粥喝得太快了，什么滋味都没尝出来，只是混了个肚饱！！\n"YEL"龙岛主无奈的摇摇头，示意仆从再给你一碗。\n你伸手想去接，又有点不好意思，犹豫再三，还是又厚着脸皮要了一碗。\n"NOR);
                ob1=new("/d/xkd/obj/zhou");
                ob1->set("owner", me);
                ob1->move(me);
         }
       destruct(this_object());
               return 1;

}
