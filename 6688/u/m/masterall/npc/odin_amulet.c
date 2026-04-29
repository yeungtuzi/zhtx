//tell 0 该睡觉了
//
///d/sunflower/treasure/odin_amulet.c
#include <ansi.h>
#include <armor.h>  
inherit NECK;
inherit F_UNIQUE;
int od;
void check();
object me = this_player();
object amulet = this_object();

void create()
{
	set_name(HIG"奥" + HIY"丁" + HIW"的" + HIC"信" + HIM"物"NOR, ({ "odin amulet" , "amulet" }));
     set_weight(50);
     set("unpawnable",1);

	//终极护身符，带多项防具属性
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "一个黑红色的护身符，上面刻着一些神秘的印记。\n"
            "隐隐的散发出一丝丝杀气\n");
            set("unit", "个");
            set("value", 0);
            set("armor_prop/armor",20);
            set("armor_prop/armor_vs_force",20);
            set("armor_prop/dodge", 15);
            set("armor_prop/parry", 15);
            set("armor_prop/defense", 15);
            set("armor_prop/spells", 50);
            set("armor_prop/armor_vs_spells", 50);
            set("wear_msg", CYN"$N把$n挂在胸前。\n\n"NOR+YEL"$N觉得世间再无甚可怕之事了。\n"NOR);
     }
     setup();
	
	call_out("check",5);
}

//让信物可以随身
string query_autoload()
{
        return query("name");
}

void autoload(string arg)
{
 set("name",arg);
}


//不让丢、卖、当、给别人
int init()
{		
		object me;
		me=this_player();
		if (!wizardp(me)) {
		set("no_get", "奥丁的信物只跟随他选定的主人！ \n");
		set("no_drop","这么做会受到奥丁的惩罚的！ \n");
		set("no_give","奥丁的信物可不是玩物，可以说给谁就给谁！");
		set("no_sell","奥丁的信物不是凡间之物，不能够拿去卖钱！");
	}
}


//实现信物的特殊功能
void check()
{
	object me, victim, *enemy, obod;
	string name;
        string *conditions=({}),*list,arg;
        int i,flag;
	string eqflag;

	remove_call_out("check");
	call_out("check",5);

	name = query("name");
	me=environment();
	if(!me) return ;
	//如果od为0，未战斗时把od赋值1，准备在战斗之初进行判断是否召唤奥丁
	if (!me->is_fighting() && (!od) ) od = 1;
	if( me->is_character() &&  ( eqflag=query("equipped")) && ( eqflag =="worn")  )
	{	
				
		if( me->is_fighting() && (od) )
		{
			//只在战斗之初判断一次是否召唤奥丁
			od = 0;
			if( random(100)>50)
			{	
				//出现奥丁
				enemy = me->query_enemy();
				i = sizeof(enemy);
				victim=enemy[random(i)];
				obod=new(__DIR__"odin");
				obod->move(environment(me));
				obod->zantetsuken(victim);
			}

			//设置奥丁参数

		}

		if(!living(me))
		{
			message_vision(name+YEL"发出嗡嗡声响，一道七彩光环在$N身边盘旋环绕，经久不散。\n",me);
			me->revive();
			return;
		}
		
	        list = get_dir("/daemon/condition/");
        
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
			me->receive_curing("sen",50);
			return;
		}			
		if( me->query("eff_gin") < me->query("max_gin") )
		{
			message_vision(MAG"一道紫色光气从"+name+MAG"上升起，反过来又注入$N顶门\n"NOR,me);
			me->receive_curing("gin",50);
			return;
		}			
		if( me->query("eff_kee") < me->query("max_kee") )
		{
			message_vision(HIC"一道青色光气从"+name+HIC"上升起，反过来又注入$N顶门\n"NOR,me);
			me->receive_curing("kee",50);
			return;
		}			

	}
}



