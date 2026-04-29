//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 混世魔剑

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
         set_name(HIC"邪剑穿灵"NOR, ({ "mojian", "jian","sword" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
//         set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是传说中的混世魔剑，据说每次它一出世，江湖中便是一片腥风血雨。\n");
                   set("value", 90000);
                set("rigidity",1000000);
                set("material", "crimson gold");
/*
        set("wield_msg", HIY"只见$N长叹一声，无可奈何地从空中把出一把混世魔剑。\n"
                HIR "\n你看见天空中一道闪电化过 ....\n\n"
                MAG     "江湖中人都知道：" HIR "混世魔剑要\n\n"
                        "\t\t重新出世了！！！！！！！！！！ ！\n\n" NOR);
        set("unwield_msg", HIW"$N一把将混世魔剑掷入地下，禁不住潸然泪下。\n" NOR);

*/
                 set("weapon_prop/attack", this_player()->query_skill("force",1));  
                 set("weapon_prop/parry", this_player()->query_skill("force",1));  
                 set("weapon_prop/defense", this_player()->query_skill("force",1));  
       }
    init_sword(300);
       setup();
}
/*

int wield()
//                 set("weapon_prop/defense", this_player()->query_skill("force",1));  
{
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}
*/

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp;
        string weap_name;
               if (damage_bonus < 0 ) return 0;

        if(victim == me) return;
        
        if( objectp(weap = victim->query_temp("weapon")) )
        {

                wap = weight() / 500
                        + query("rigidity")
                        + me->query("str");

                wdp = (int)weap->weight() / 500
                        + (int)weap->query("rigidity")
                        + (int)victim->query("str");

                      if(  random(wap) > wdp )
                {
                        weap_name = weap->query("name");
                        weap->unequip();
                        weap->move(environment(victim));
                        weap->set("name", "断掉的" + weap->query("name"));
                      weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        weap->set("long", weap->query("long")+"可是，现在却已经断为两截，不知道还有什么用处。\n");
                        victim->reset_action();
                        return "只听$N一声暴喝，$n手中的" + weap_name
                                + "已被$N挟雷霆万钧之势砸断！\n";
                }
                                
        }
        else 
        victim->receive_wound("kee",damage_bonus/4);
        victim->receive_wound("sen",damage_bonus/8,me);
        return this_object()->name()+ HIR "在$n的$l轻轻划过，$n的伤口立刻觉得如同火烧一般疼痛，顿时鲜血狂飙！\n"+HIW"混世"+HIR"魔"+HIC"剑"+HIC"发出异样的光芒，使$n不由得打了一个寒战！\n" NOR;
}
void init()
{
        if( this_player()==environment() )
{            add_action("do_pray","pray"); 
             add_action("do_jiedu","jiedu"); }
}

int do_pray(string arg)
{
      string name;
      string home;
      object *inv;
      int i;
       name = (string)this_player()->query("name");
        if( this_player()->is_busy() )
                return notify_fail("你正忙着呢，还是省省吧，飞来飞去的很好玩么？\n");

         if( !arg || arg!="start" ) return notify_fail("你要祈求什麽? \n");
         {
         message_vision(HIW"$N披发仗剑，喃喃的吟诵....\n"
             "全身不断的发出闪耀的光芒。 突然一道霹雳.... \n"NOR,this_player() );
         this_player()->receive_damage("sen",10);
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


int do_jiedu(string arg)
{
        string *conditions=({}),*list;
        int i;
        int has_poison;
        object me,target;

        me=this_player();
        target = present(arg, environment(this_player()));            


         if( !arg)   
         return notify_fail("你要给谁解毒?\n");
  //      if( me->is_fighting() )
  //              return notify_fail("战斗中运功解毒？找死吗？\n");

        if( (int)me->query("force") < 50 ) 
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");
        
        if( target != me )
                message_vision(
                        HIG "$N将兵器搭在$n的疮口上，发动体内的真气吸取$n身上的毒素....\n"NOR,me, target );
        else
                message_vision(
                        HIG "$N将兵器搭在自己的疮口上，发动体内的真气吸取身上的毒素...\n"NOR,me);

        list = get_dir("/daemon/condition/");
        
        i = sizeof(list);
        while( i-- )
        {
                arg = list[i];
                if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                        conditions += ({arg[0..strlen(arg)-3]});
        }
        
        i = sizeof(conditions);
        has_poison=0;
        while(i--) 
        {
                if( target == me )
                {
                        if( (int)me->query("force") < 50 ) 
                                return notify_fail("你的真气不够。\n");
                        if( me->query_condition(conditions[i]) > 0 )
                        {
                                me->apply_condition(conditions[i],0);
                                message_vision(HIG"过了不久，$N额头上冒出豆大的汗珠，从手指尖滴出一缕黑血，黑血渐渐由黑转红...\n"NOR,me);

                                if( wizardp(me) )
                                        message_vision("$N的"+conditions[i]+"被解啦。\n",me);
                                me->add("force",-50);
                                has_poison = 1;
                        }
                }
                else
                {
                        if( (int)me->query("force") < 50 ) 
                                return notify_fail("你的真气不够。\n");

                        if( target->query_condition(conditions[i]) > 0 )
                        {
                                target->clear_condition();
                                message_vision(HIG"真武剑不断的由绿转黑，再由黑转绿，"+HIC"\n$n的疮口冒出“嗤嗤”的白烟，不多一会，$n的脸上恢复了红润...\n"NOR,me,target);
                                if( wizardp(me) )
                                        message_vision("$n的"+conditions[i]+"被$N解啦。\n",me,target);
                                me->add("force",-50);
                                has_poison = 1;
                        }
                }       
        }
        
        if(!has_poison) return notify_fail("毒素已吸净！\n");

        write("Ok。\n");
        return 1;

}



