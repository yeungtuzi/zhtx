//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 暗灵

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit SWORD;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name( BLK "暗灵" NOR, ({ "an ling","jian" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
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
                set("rigidity",10000);
                set("material", "steel");
                set("wield_msg", "$N将$n从鞘中拔出，高举过顶，虔诚地握在手中，一股彷佛代表死神的森然之气笼罩着一切。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘，顿时一切似乎恢复了活力。\n");

                set("weapon_prop/spirituality", this_player()->query_skill("necromancy",1)/6); 
                set("weapon_prop/astral_vision", 1);          
                set("weapon_prop/spells", this_player()->query_skill("spells",1)/10);       
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
        if( this_player()->query_skill("spells",1) < 250 )
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

        if( victim->is_ghost() || victim->query("env/invisibility") ) {
                if( random(me->query("max_atman")) > 
(int)victim->query("atman")/2 ) {
                        damage = me->query_spi();
                        victim->receive_wound("gin", damage*5);
                        me->receive_heal("gin", damage);
                        me->receive_heal("kee", damage);
                        me->receive_heal("sen", damage);
                        return name()+BLK"发出一道黑色的罡气，罩住$n的全身。\n" NOR;
                }
                return random(me->query_spi());
        }
}

void init()
{
        if( this_player()==environment() )
            add_action("do_pray","pray");
}
int do_pray(string arg)
{
      string name;
      string home;
      object *inv;
      int i;
if( this_player()->is_busy() )
                return notify_fail("你正忙着呢。\n");
if( this_player()->is_fighting() )
                return notify_fail("战斗中还能分神祈祷？呵呵。\n");

       name = (string)this_player()->query("name");

         if( !arg || arg!="start" ) return notify_fail("你要祈求什麽? \n");
         {
         message_vision(HIW"$N披发仗剑，喃喃的吟诵....\n"
             "暗灵不断的发出闪耀的光芒。 突然一道霹雳.... \n"NOR,this_player() );
         this_player()->receive_damage("sen",50);
         if( random(3) ) return(1);     
         inv = all_inventory(this_player());
                for( i=0;i<sizeof(inv);i++) {
                        if( inv[i]->is_character() )
                                return 1;
                }
        home = this_player()->query("startroom"); 
         tell_room(environment(this_player()),
               name+HIC"的身影消失在空气中。\n"NOR,this_player() );
         tell_room(home,
              name+HIC"的身影出现在一阵烟雾之中。\n"NOR,this_player() );
         this_player()->move(home);
          }
          return 1;
}

