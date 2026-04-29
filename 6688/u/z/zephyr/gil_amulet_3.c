//gil_amulet.c
#include <ansi.h>
#include <armor.h>  
inherit __DIR__"bingqipu";
void check();
int bonus_damage(object me, object victim, int bonus);

int gil, wake;

void create()
{
        set_name(YEL"纵横"GRN"兵器谱"NOR, ({ "bingqi pu" , "zongheng bingqipu", "bingqipu", "amulet", "pu" }));
     set_weight(50);
     set("unpawnable",1);

        //终极护身符，带多项防具属性
     if ( clonep() )
              set_default_object(__FILE__);
     else {
        set("long",YEL@LONG

斩铁剑：盘古死后乘乱捡得，上古神物，吾不敢多言。
        无视对方防御力，无属性杀伤。特殊效果：破甲； 
        
出跸刀：名刀出跸，乃一柄黄杨木雕的弯刀，无鞘，刀身长三尺半，上面雕
        有美人出跸图，图上人物凡143，马匹109，车辆16，云麾、车盖、仪仗等
        均历历可数，据说这些东西如果放为原大，那就要前后排上十来里长，如果
        化成图画，裱上手卷，也得绵延十数丈。画与雕刻都出自名家，形态逼真，
        神情生动。
	无属性攻击。特殊效果：不知

七修剑：为当年七修真人镇山之宝，属上古降魔利器。该剑既出，能幻出道道
        金白之光，光到之处，杀伤力极强。七修真人后将此剑传与杜铁池。
        杜铁池得此宝后，降妖伏魔，大建奇功，后杜铁池成为七修门掌门。
        金属性攻击。特殊效果：破兵器

假七修剑：年少轻狂之时为奸贾所欺，重金所购赝品。吾生平第一大辱，留之
        自醒。
        无视防御力，金属性攻击

刈鹿刀：春秋战国时铸剑名徐夫人之嫡裔徐鲁子耗尽毕生精力铸成，其名取意
        “秦失其鹿，天下共逐，唯胜者得鹿而刈之。”此刀色泽淡青，杀人不见血
        迹。
        无属性攻击。特殊效果：嗜血

灵空剑：神兵利器，由铸剑大师邵空子炼成，未几邵大师请一名宿相此宝剑，
        那名宿却认为是一柄凶剑，剑身上光纹四射如火，主大凶，佩带都必定招
        致不详，甚至会有家破人亡之祸。
        无属性攻击。特殊效果：自伤伤人


LONG NOR
         );

                        set("unit", "册");
            set("value", 0);
            set("armor_prop/damage",270);
            set("armor_prop/armor",170);
            set("armor_prop/armor_vs_force",200);
            set("armor_prop/defense",22);
            set("armor_prop/attack", 51);
            set("wear_msg", CYN"$N把$n塞在胸前口袋，虔诚的祈祷。\n\n"NOR+YEL"$N顿时觉得一股真气在体内流动，神采奕奕。\n"NOR);
     }
     setup();
        
        call_out("check",5);
}


//随机召唤功能
void check()
{
        object me, victim, *enemy, obod;
        string name;
    //string *conditions=({}),*list,arg;
    int i, all, player_gil_flag, heal_kee, maxkee, effkee, kee;
        int bonus = 0;

		//int flag;
        string eqflag;

        remove_call_out("check");
        call_out("check",5);

        name = query("name");
        me = environment();

        //if (wizardp(me))      tell_object(me,"wearer is "+ me->name() +"\n");


        player_gil_flag = me->query("gil_flag") + 500;


        if(!me) return ;

        //如果gil为0，未战斗时把gil赋值1，准备在战斗之初进行判断是否召唤基加美修
        if (!me->is_fighting() && (!gil) )      gil = 1;
        if( living(me) && (!wake) )     wake = 1;
        
        //if (wizardp(me))      tell_object(me,"gil is "+ gil +"\n");

        if( me->is_character() &&  ( eqflag=query("equipped")) && ( eqflag =="worn")  )
        {       
                if( me->is_fighting() && (gil) && !me->query_condition("zhaohuan_weaponor" ) )
                {
                        //只在战斗之初判断一次是否召唤基加美修
                        gil = 0;
                        if( random(100)>75 && random(player_gil_flag) > 450)
                        {       
                                //if (wizardp(me)) tell_object(me,"召唤出兵器贩子\n");

                                //出现基加美修
                                enemy = me->query_enemy();
                                all = sizeof(enemy);
                                if( !all ) return;
                                obod=new(__DIR__"gilgamesh_3");
                                obod->move(environment(me));
                                
								me->apply_condition("zhaohuan_weaponor", 5+random(20) );

                                //攻击所有敌人

                                for(i=0;i<all;i++)
                                {
                                        victim = enemy[i];      
                                        //message_vision(HIY"攻击敌人\n"NOR,environment());
                                        obod->slash(victim,me);
                                }
                                if (present(obod,environment(me)))
                                {
                                        obod->leave();
                                }
                        }

                }

                if( !living(me) && (wake) )
                {
                        wake = 0;
						victim = me->query_temp("last_damage_from");

                        if( random(100)>40 && random(player_gil_flag) > 1500)
                        {
                                message( "vision", HIY "\n你的眼前突然出现一团耀眼的光芒，光芒中浮现出一个人影！\n\n" NOR, environment(me));
                                message_vision( HIY "兵器贩子一手放在"+ me->name() +"的天灵盖上, 一手贴在" + me->name() +"的后心, 闭上眼睛缓缓低吟...\n" NOR, environment(me) );
                                me->revive();
								heal_kee = 1000 + random(player_gil_flag);
								maxkee = (int) me->query("max_kee");
								effkee = (int) me->query("eff_kee");
								kee = (int) me->query("kee");
								bonus = heal_kee - maxkee;

								if (bonus<1)
									bonus=0;
								if (bonus>5000)
									bonus=5000;

                                if ( maxkee < heal_kee )
                                {
                                    heal_kee = maxkee;
                                }
                                if ( effkee < maxkee && effkee < heal_kee && kee < heal_kee )
                                {
                                        me->set("eff_kee",heal_kee);
                                        me->set("kee",heal_kee);
                                }

                                me->set("kee",heal_kee);

							    if ( objectp(victim) && bonus && !environment(me)->query("no_fight") && present(victim, environment(me) ) && !(victim==me) )
								{
									message_vision(HIW "兵器贩子腾空飞起，暴喝一声．．．\n" NOR, me);
									message_vision(HIR "．．．兵器贩子全身发出炽热的血红光芒！！！\n" NOR, me);
									bonus_damage(me, victim, bonus);
								}
								
                                me->set("eff_gin", (int)me->query("max_gin"));
                                me->set("gin", (int)me->query("max_gin"));
                                me->set("eff_sen", (int)me->query("max_sen"));
                                me->set("sen", (int)me->query("max_sen"));   

                                message_vision( HIY "兵器贩子低头闭目，开始施展游识神通 ....\n" NOR, environment(me));
                                message( "vision", HIY "\n一道耀眼的光芒忽然罩住兵器贩子，几秒钟後，光芒和人一齐消失得无影无踪！\n\n"NOR, environment(me));               
                        }
                        return;
                }
                
/*              list = get_dir("/daemon/condition/");
        
                i = sizeof(list);
                conditions = ({});
                flag = 0;
                while( i-- )
                {
                        arg = list[i];
                        if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                                conditions += ({arg[0..strlen(arg)-3]});
                        conditions += ({"iceshock"});
                        conditions += ({"threesmile"});
                        conditions += ({"zhang_qi"});
                }
        
                i = sizeof(conditions);

                while(i--) 
                {
                        if( me->query_condition(conditions[i]) > 0 )
                        {
                                me->apply_condition(conditions[i],0);
                                flag = 1;
                        }
                }                               
                if(flag)
                {

                        message_vision(name+GRN"上面突然闪过一阵异芒，从$N手指出吸出一道黑气。\n"NOR,me);
                        return;

                }

                if( me->query("eff_sen") < me->query("max_sen") )
                {
                        message_vision(HIW"一道白色光气从"+name+HIW"上升起，反过来又注入$N顶门\n"NOR,me);
                        me->receive_curing("sen",100);
                        return;
                }
                
                if( me->query("eff_gin") < me->query("max_gin") )
                {
                        message_vision(MAG"一道紫色光气从"+name+MAG"上升起，反过来又注入$N顶门\n"NOR,me);
                        me->receive_curing("gin",100);
                        return;
                }
                
                if( me->query("eff_kee") < me->query("max_kee") )
                {
                        message_vision(HIC"一道青色光气从"+name+HIC"上升起，反过来又注入$N顶门\n"NOR,me);
                        me->receive_curing("kee",100);
                        return;
                }                       
*/
        }
}

int do_feel(string arg)
{
	int player_gil_flag = this_player()->query("gil_flag") + 500;
	int value = 25 * (player_gil_flag - 800) /  player_gil_flag;
	int w = 60 * (player_gil_flag - 1500) /  player_gil_flag;

	if( arg != query("id") ) return 0;
	tell_object( this_player(),YEL"你和兵器贩子的相性目前是"+this_player()->query("gil_flag")+"\n"NOR);
	if (wizardp(this_player()))     tell_object( this_player(),YEL"战斗中召唤出现兵器贩子的几率是"+(string)value+"%。\n"NOR);
	if (wizardp(this_player()))     tell_object( this_player(),YEL"昏迷中被救醒的几率是"+(string)w+"%。\n"NOR);
	if (wizardp(this_player()))     tell_object( this_player(),YEL"还需要消耗"+(string)this_player()->query_condition("zhaohuan_weaponor") +"点食物才有机会召唤兵器贩子。\n"NOR);
	return 1;
}

//比例攻击
int bonus_damage(object me, object victim, int bonus)
{
		int damage, effkee;
		effkee = victim->query("eff_kee");

        message_vision(HIR "\n炽热的红光象利剑般射向$N，\n" NOR, victim);
        victim->receive_wound("sen", random(2) , me);
        victim->receive_wound("gin", random(2) , me);
        if (!objectp(victim)) return 1;
        if(victim->is_ghost()==1) {
                message_vision(YEL "$N惨叫了一声，化为了灰烬！\n" NOR, victim);
                victim->die();
                return 1;
        }
        if(victim->is_zombie()==1) {
                message_vision(YEL "$N惨叫了一声，化为了一滩血水！\n" NOR, victim);
                victim->die();
                return 1;
        }
		//比例计算
		bonus*=2;
		bonus = bonus/100;
		if (bonus<10)
			bonus=10;
		if (bonus>90)
			bonus=90;
		damage = effkee * bonus/100;

		if (damage<1)
			damage=1;

        if(userp(victim))
        {
			victim->receive_damage("kee",damage,me);
			COMBAT_D->report_status(me,victim,1);
			if (wizardp(me)) tell_object(me,"造成对方气伤害 "+ damage +"点，是"+bonus+"％对方eff_kee\n");
        }
        else
        {
			victim->receive_wound("kee",damage,me);
			COMBAT_D->report_status(me,victim,1);
			victim->kill_ob(me);
			me->fight_ob(victim);
			if (wizardp(me)) tell_object(me,"造成对方气伤害 "+ damage +"点，是"+bonus+"％对方eff_kee\n");
        }
        return 1;
}
