// pilidan.c 霹雳弹

inherit ITEM;
#include <ansi.h>
#include <combat.h>
inherit SSERVER;    

void create()
{
        set_name(HIW"霹雳"+HIY"雷火"+HIR"弹"NOR, ({"pili dan", "dan"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一粒精致但威力无比的霹雳雷火弹，好比念珠般大小，中藏烈性火药，以强力弹簧机括发射。\n");
                set("unit", "粒");
                set("value", 0);
        }
}

void init()
{
        add_action("do_tan","tan");
}

int do_tan(string arg)
{                         
        object me,target,obj;
        int i,j,damage1,damage2,level,ap,dp,x,y,z;      
        string skill;            
                              
        if( !arg)       return notify_fail("你要向谁弹射霹雳雷火弹？\n");                                                            

        me=this_player();
        target = present(arg, environment(this_player()));            

        if( !objectp(target) )
                return notify_fail("这里没有这个人。\n");  

        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("你只能在战斗中使用暗器。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") ) 
                return notify_fail("空手才可以使用霹雳雷火弹。\n");

        if(me->query("family/family_name") != "乾坤教" && me->query("family/family_name") != "天邪派")  
                return notify_fail("你与峨嵋素与来往，怎么得到这种暗器的？\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
                       
        if( me->is_busy() )     return notify_fail("你正在忙别的，腾不出手来发暗器。\n");

        if( me->query("shen") >= 0 )     
                return notify_fail("你太善良了，这么阴戾的暗器还是别用的好。\n");

        if( me->query_skill("throwing", 1) < 200 )     
                return notify_fail("你的暗器手法还不够娴熟。\n");

        if( me->query("force") < 2000 )     
                return notify_fail("你的内力不够。\n");

        i=me->query_skill("throwing");
        j=target->query("combat_exp");
                          
        if( j==0 )      j=1;
        ap = (i/100)*i*i;
        dp = j/40;
        x = random(ap/2 + dp);
        y = random(ap + dp );
        z = random(ap + dp/2 );


        me->add("force",-400);
        message_vision(HIB"$N将真气汇于指尖，将"HIW"霹雳"+HIY"雷火"+HIR"弹"+HIB"扣在掌心，含笑而立，中指轻弹，有如拈花微笑。\n"NOR,me);
        message_vision(HIM"突然间嗖的一响，破空之声极强，一枚小小念珠对着$n激射而至！\n"NOR,me,target);

        if( x > dp)
        {
               message_vision(HIR"\n只听得砰的一声巨响，这枚念珠直中$n的后脑炸了开来，一时间$n的半个脑袋已然不知去向！\n"NOR,me,target);
               target->set_temp("last_damage_from",me);
               target->add("eff_kee",-1*(target->query("max_kee")/3 + 400 + random(800)));
               target->set("force_factor", 0);
               COMBAT_D->report_status(me,target,1); 
               me->start_busy(3);
        }
        else if( y > dp)
        {
               message_vision(HIY"\n只听得砰的一声巨响，这枚念珠正中$n的前胸，$n被炸力一撞，已然变得血肉模糊，惨不堪言！\n"NOR,me,target);
               target->set_temp("last_damage_from",me);
               target->add("eff_kee",-1*(target->query("max_kee")/6 + 200 + random(200)));
               target->start_busy(8);
               COMBAT_D->report_status(me,target,1); 
               me->start_busy(3);
        }
        else if( z > dp/2)
        {
               message_vision(HIG"\n只听得砰的一声巨响，这枚念珠正中$n的臀部，$n的半边屁股被炸得万朵桃花开！\n"NOR,me,target);
               target->set_temp("last_damage_from",me);
               target->add("eff_kee",-1*(target->query("max_kee")/9 + 100 + random(100)));
               target->add_temp("apply/parry", -i/5);
               target->add_temp("apply/dodge", -i/5);
               target->add_temp("apply/attack", -i/5);
               COMBAT_D->report_status(me,target,1); 
               me->start_busy(3);
        }
        else 
        {
               message_vision(HIW"\n$n冷哼了一声，身子如纸鸢般向后飞出数丈，飘飘然闪开了这记惊天骇地的霹雳弹！\n"NOR,me,target);
               me->start_busy(5);
        }
                destruct(this_object());
        return 1;
}

