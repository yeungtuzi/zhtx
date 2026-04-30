//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 铁罗汉

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit GLOVE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIW"铿锵"+HIY"铁云"+HIR"拳"NOR, ({ "kengqiang tieyun quan", "quan" }) );
        set_weight(1);
        set("no_sell",1);
        set("no_paimai",1);                           
        set("no_drop",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long",   "一副殷红色的铁拳套，上面有不少刀砍斧斫的痕迹，显然当年随着它的主人身经百战。\n据说它有一种神奇的力量，葬身在其拳下的人死前都没有丝毫的痛苦。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "iron");
                set("wield_msg",
                        HIY "$N将$n"+HIY"套在手上，眼中立刻精芒四射，刹那间充满了斗志和自信。\n"NOR);
                set("unequip_msg", HIG "$N将$n"+HIG"收回囊中，弥漫在四周杀气顿时消散。\n"NOR);
                set("weapon_prop/attack", 50);   
                set("weapon_prop/parry", 50);  
                set("weapon_prop/dodge", 50);
                set("weapon_prop/courage", 50);
                set("weapon_prop/courage", 50);
        }
    init_glove(320);
       setup();
}

int wield()
{
        if( this_player()->query_skill("ill-quan",1) < 200)
        {
                return notify_fail("你的病维摩拳等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这副拳套。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        // 2026-04-30: unused variable commented out
        // object weap;
        // 2026-04-30: unused variable commented out
        // string weap_name;
        if (damage_bonus < 0 ) return 0;
        if(victim == me) return;
        if(random(3)>0)
        if(userp(victim)){
        victim->add("force", -1*me->query("force")/10);
        return query("name")+HIY"重重地击中了$n的$l，$n只觉得气血翻涌而来，真气行走不畅，\n好像地狱圣火喝多了酒想要吐，干咳了几声，却什么也吐不出来！\n"NOR;
        }else{
        victim->add("combat_exp",-1*victim->query("combat_exp")/10);
        return query("name")+HIG"轻轻触击到$n的$l上，$n立即感到一种奇异的幻觉，\n"+HIC"什么王侯霸业，什么一统天下，什么武林至尊，皆为过眼云烟，\n"+HIM"$n觉着自己似乎回复到童年时的天真烂漫，脸上不由幸福的一笑，露出两个浅浅的酒窝，煞是可爱！\n"NOR;
          }
}


