//gil_amulet.c
#include <ansi.h>
#include <armor.h>  
inherit NECK;
int gil;
void check();
object me = this_player();
object amulet = this_object();

void create()
{
        set_name(YEL"纵横"CYN"兵器谱"NOR, ({ "bingqi pu" , "zongheng bingqipu", "bingqipu", "amulet", "pu" }));
     set_weight(50);
     set("unpawnable",1);

        //终极护身符，带多项防具属性
     if ( clonep() )
              set_default_object(__FILE__);
     else {
        set("long",YEL@LONG

斩铁剑：盘古死后乘乱捡得，上古神物，吾不敢多言。
        无视对方防御力，无属性杀伤。特殊效果：破甲； 
        
破残：原为名刀出跸，乃一柄黄杨木雕的弯刀，无鞘，刀身长三尺半，上面雕
        有美人出跸图，图上人物凡143，马匹109，车辆16，云麾、车盖、仪仗等
        均历历可数，据说这些东西如果放为原大，那就要前后排上十来里长，如果
        化成图画，裱上手卷，也得绵延十数丈。画与雕刻都出自名家，形态逼真，
        神情生动。这柄木刀最后毁于一柄同样形状、刻有“小楼一夜听春雨”的魔
        刀，但持魔刀者却丧命于这柄出跸刀之下。此刀破后，天下无人可修补。
        后来因机缘巧合为吾所得，于天山北麓寒于洞，费三年心血，合万年冰魄，
        才有此刀。此刀经此大难，已失往日犀利，攻击能力忽强忽弱，名之：破残
        无视对方防御力，冰冻属性攻击

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
            set("armor_prop/damage",250);
            set("armor_prop/armor",200);
            set("armor_prop/armor_vs_force",200);
            set("armor_prop/defense",20);
            set("armor_prop/attack", 50);
            set("wear_msg", CYN"$N把$n塞在胸前口袋，虔诚的祈祷。\n\n"NOR+YEL"$N顿时觉得一股真气在体内流动，神采奕奕。\n"NOR);
     }
     setup();
        
        call_out("check",5);
}

//随身
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
                set("unpawnable",1);
                set("no_get", "此乃武林至宝，不可随意拾取！ \n");
                set("no_put", "此乃武林至宝，不可到处乱放！ \n");
                set("no_paimai", "拿去拍卖，被邪魔外道买了去怎么办！ \n");
                set("no_drop","武林至宝，怎可随意乱丢！ \n");
                set("no_give","兵器谱不可随意送人，如果落入邪魔之手，生灵涂炭！");
                set("no_sell","兵器谱乃宝物，店铺不敢收取！");
        }
}


//随机召唤功能
void check()
{
        object me, victim, *enemy, obod;
        string name;
    //string *conditions=({}),*list,arg;
    int i, all, player_gil_flag;
        //int flag;
        string eqflag;

        remove_call_out("check");
        call_out("check",5);

        name = query("name");
        me = environment();

        player_gil_flag = me->query("gil_flag") + 500;

        if(!me) return ;
        //如果od为0，未战斗时把od赋值1，准备在战斗之初进行判断是否召唤基加美修
        if (!me->is_fighting() && (!gil) ) gil = 1;
        if( me->is_character() &&  ( eqflag=query("equipped")) && ( eqflag =="worn")  )
        {                       
                if( me->is_fighting() && (gil) )
                {
                        //只在战斗之初判断一次是否召唤基加美修
                        gil = 0;
                        if( random(100)>70  && random(player_gil_flag) > 450)
                        {       


                                //出现基加美修
                                enemy = me->query_enemy();
                                all = sizeof(enemy);
                                if( !all ) return;
                                obod=new(__DIR__"gilgamesh");
                                obod->move(environment(me));

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


        }
}

