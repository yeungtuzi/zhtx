//By masterall for 暗灵

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;


void create()
{
        set_name( BLK "暗灵" NOR, ({ "an ling","jian" }) );
        set_weight(1);
        set("no_sell",1);
        set("no_paimai",1);
        set("no_drop",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",@long                      
  这是一把黑灰色用桃木雕成的古剑，闻起来有一股香味，剑身刻著许多你
从未见过的咒文，每次握上剑柄，总有一股森然之气砭人肌肤，传说中，有
一把来自地狱的死亡之剑，当年引起了江湖中的一场腥风血雨，后来才被九
幽神君得到后封存起来。那把剑在二十年前的一个晚上神秘失踪。莫非，这
就是传说中那把的终极法器？
long
);
                set("value", 0);
                set("rigidity",5000);
                set("material", "steel");
                set("wield_msg", "$N将$n从鞘中拔出，高举过顶，虔诚地握在手中，一股彷佛代表死神的森然之气笼罩着一切。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘，顿时一切似乎恢复了活力。\n");

                set("adv_props/spirituality", 50); 
                set("adv_props/spells", 30);       
        }
    init_sword(44);
       setup();
}

int query_mana_imp()
{
        return 5;                               
}


int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        if( this_player()->query_skill("spells",1) < 200 )
        {
                tell_object(this_player(),"你的手刚刚握上"+name()+"，只觉得一股只有可能来自地狱的阴气上涌，无可抵御...\n");
                message_vision(name()+BLK"发出一道黑色的罡气，罩住$N的全身。\n" NOR,this_player());
                this_player()->receive_wound("sen",100);
                this_player()->unconcious();
                return 0;               
        }
        return ::wield();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
                int damage;

                if( random(me->query("max_atman")) > (int)victim->query("atman")/2 ) 
                {
                        damage = me->query_spi() + me->query_msc() + me->query("mana_factor");
                        victim->receive_wound("gin", damage);
                        me->add("mana", damage);
                        if(me->query("mana")>me->query("max_mana")*2)
                        me->set("mana", me->query("max_mana")*2);
                      
        return name()+BLK"发出一道黑色的罡气，罩住$n的全身，$n只感觉自己的精力正在被$N一点一点的压榨直至枯竭！\n" NOR;
                }

}

