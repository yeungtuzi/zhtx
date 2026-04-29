//odin_amulet.c
#include <ansi.h>
#include <armor.h>  
inherit WAIST;

void create()
{
	set_name( GRN"辟邪温玉"NOR, ({ "pixie wenyu" , "jade" }));
     set_weight(10);
     set("unpawnable",1);

     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", GRN"一块暗绿色的玉佩。上面雕刻着美丽的花纹。\n"NOR);
            set("unit", "块");
            set("value", 0);
            set("armor_prop/armor",50);
            set("armor_prop/armor_vs_force",20);
            set("armor_prop/dodge", 5);
            set("armor_prop/parry", 5);
            set("armor_prop/defense", 5);
            set("armor_prop/spells", 50);
            set("armor_prop/armor_vs_spells", 100);
            set("wear_msg", CYN"$N把$n挂在腰间。\n\n"NOR);
     }
     setup();
}


string query_autoload()
{
        return query("name");
}

void autoload(string arg)
{
 set("name",arg);
}


int init()
{		
		object me;
		me=this_player();
		if (!wizardp(me)) {
                set("unpawnable",1);
                set("no_get", "这不是你的东西，不要乱拣！ \n");
                set("no_put", "辟邪温玉不可到处乱放！ \n");
                set("no_paimai", "拿去拍卖，被邪魔外道买了去怎么办！ \n");
                set("no_drop","辟邪温玉怎可随意乱丢！ \n");
                set("no_give","辟邪温玉不可随意送人！");
                set("no_sell","辟邪温玉乃宝物，店铺不敢收取！");
		}
        add_action("do_zhaohuan","zhaohuan");     

}

int do_zhaohuan()
{
        object guard;
        object me,enemy;
        me=this_player();


        if(!enemy) enemy=me;

        if( !me->is_fighting() )
                return notify_fail("没什么事情最好不要打扰别人。\n");

        if( !enemy->is_fighting() )
                return notify_fail(enemy->name()+"好好的，召唤什么。\n");
		if( me->query_temp("dingpeng_amulet") >= 1 ) return notify_fail("人家已经在帮助你了，还想怎么样？\n");

        if( (int)me->query("atman") < 300 )
                return notify_fail("你的灵力不够了！\n");
        if( (int)me->query("sen") < 30 )
                return notify_fail("你的精神无法集中！\n");

        message_vision(GRN"$N刺破左手中指，按在辟邪温玉上面，默默呼唤道：快来相助！\n"NOR, me);
        me->add("atman", -300);
        me->receive_damage("sen", 30);
		
		if( me->query("eff_kee") > me->query("max_kee")*50/100)     
                return notify_fail("没什么紧急情况，最好不要打扰别人。\n");

		if( random(100)>10) 
		{
                message("vision", "但是什麽也没有发生。\n", environment(me));
				me->start_busy(random(3));
                return 1;
        }

        seteuid(getuid());
        guard = new(__DIR__"guard"); 

        guard->move(environment(enemy));
        guard->set_level(me->query_skill("force",1));
        guard->invocation(enemy);
        return 1;
}

