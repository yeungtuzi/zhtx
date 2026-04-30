// combatd.c

// MudOS v21.6 #pragma optimize's jump threading has bug! (line 200)
//#pragma optimize
inherit F_DBASE;


#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


//move to here,should be in function do_attack()
//if put there,there will be a "too many local variables" error.
        int ap, dp, pp,coefficient;
        int damage, damage_bonus, defense_factor;
        int damaged = 0, wounded = 0;
        // 2026-04-30: unused variable commented out
        // int cost;
        mapping prepare;
        int absorb_vic, bounce = 0;
        object *partner_ob=({}),partner;
int winner_task(object,object);
int pkers_punish(object);
string *guard_msg = ({
        CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
        CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
        CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
        CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
        CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR,
});

string *catch_hunt_msg = ({
        HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
        HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
        HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
        HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
        HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
        HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
        HIW "$N喝道：「$n，看招！」\n" NOR,});

string *winner_msg = ({
        CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
        CYN "\n$N双手一拱，笑著说道：承让！\n\n" NOR,
        CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
        CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
     	CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
        CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});

void create()
{
        seteuid(getuid());
        set("name", "战斗精灵");
        set("id", "combatd");
}

string damage_msg(int damage, string type)
{
        string str;

//      return "造成 " + damage + " 点" + type + "。\n";

        if( damage == 0 ) return "结果没有造成任何明显的伤害。\n";

        switch( type ) {
        case "□伤":
        case "割伤":
                if( damage < 10 ) return "结果只是轻轻地划破$p的皮肉。\n";
                else if( damage < 20 ) return "结果在$p$l划出一道细长的血痕。\n";
                else if( damage < 40 ) return "结果「嗤」地一声划出一道伤口！\n";
                else if( damage < 80 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
                else if( damage < 160 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
                break;
        case "刺伤":
                if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
                else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
                else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许\！\n";
                else if( damage < 80 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
                else if( damage < 160 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
                break;
        case "瘀伤":
                if( damage < 10 ) return "结果这一击只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
                else if( damage < 20 ) return "结果这一击在$p的$l造成一处瘀青。\n";
                else if( damage < 40 ) return "结果$N一击命中，$n的$l登时肿了一块老高！\n";
                else if( damage < 80 ) return "结果$N一击命中，$n闷哼了一声显然吃了不小的亏！\n";
                else if( damage < 120 ) return "结果只听「砰」地一声，$n退了两步！\n";
                else if( damage < 160 ) return "结果$N这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
                else if( damage < 240 ) return "结果这一下重重地击中，$n「哇」地一声吐出一口鲜血！\n";
                else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
	             break;
        case "抓伤":
                if( damage < 10 ) return
"结果只是轻轻地抓到，比抓痒稍微重了点。\n";
                else if( damage < 20 ) return "结果在$p的$l抓出几条血痕。\n";
                else if( damage < 40 ) return
"结果一抓命中，$n的$l被抓得鲜血飞溅！\n";
                else if( damage < 80 ) return
"结果「嗤」地一声，$l被抓得深可见骨！！\n";
                else if( damage < 120 ) return
"结果一抓命中，$n的$l被抓得血肉横飞！！！\n";
                else if( damage < 160 ) return
"结果这一下「嗤」地一声抓得$n连晃好几下，差一点摔倒！\n";
                else if( damage < 240 ) return
"结果$n哀号一声，$l被抓得筋断骨折！！\n";
                else return
"结果只听见$n一声惨嚎，$l被抓出五个血窟窿！鲜血溅得满地！！\n";
                break;
        case "反弹伤":
                if( damage < 5 ) return
"$N受到$n$z的反震，闷哼一声。\n";
                else if( damage < 10 ) return
"$N被$n的$z震得气血翻腾，大惊失色。\n";
                else if( damage < 20 ) return
"$N被$n的$z震得站立不稳，摇摇晃晃。\n";
                else if( damage < 40 ) return
"$N被$n以$z反震，「嘿」地一声退了两步。\n";
                else if( damage < 80 ) return
"$N被$n的$z反弹回来的力量震得半身发麻。\n";
                else if( damage < 120 ) return
"$N被$n的$z反弹力一震，胸口有如受到一记重击，连退了五六步！\n";
                else if( damage < 160 ) return
"$N被$n的$z一震，眼前一黑，身子向後飞出丈许！！\n";
                else return
"$N被$n的$z一震，眼前一黑，狂吐鲜血，身子象断了线的风筝向後飞去！！\n";
                break;

        default:
                if( !type ) type = "伤害";
                if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
                else if( damage < 20 ) str = "结果造成轻微的";
                else if( damage < 30 ) str = "结果造成一处";
                else if( damage < 50 ) str = "结果造成一处严重";
                else if( damage < 80 ) str = "结果造成颇为严重的";
                else if( damage < 120 ) str = "结果造成相当严重的";
                else if( damage < 170 ) str = "结果造成十分严重的";
            else if( damage < 230 ) str = "结果造成极其严重的";
                else str =  "结果造成非常可怕的严重";
                return str + type + "！\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
        if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
        if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
        if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
        if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
        if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
        if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
        if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
        if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
        if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
        return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio)
{
    if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
        if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
        if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
        if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
        if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
        if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
        if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
        if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
        if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
        return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

varargs void report_status(object me,object ob, int effective)
{
                if( effective ) 
                        message_combat(4, "( $N" + eff_status_msg(
                                (int)ob->query("eff_kee") * 100 / (int)ob->query("max_kee") ) 
                                + " )\n",ob,me);
                else
                        message_combat(4, "( $N" + status_msg(
                                (int)ob->query("kee") * 100 / (int)ob->query("max_kee") ) 
                                + " )\n",ob,me);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
        int status, level, power, a_d_ratio,gin_ratio,sen_ratio;
        int eff_level,afford;
        string map_skill;

        if( objectp(ob) )
        {
                if( intp(ob->query("env/attack")) )
                        a_d_ratio = (int)ob->query("env/attack");
                else 
                        a_d_ratio = 50;
        }

        if( a_d_ratio == 0) 
                a_d_ratio = 50;
        else if( a_d_ratio > 100)
                 a_d_ratio = 100;
        else if( a_d_ratio < 0)
                 a_d_ratio = 1;
      
                
        ob->set("env/attack",a_d_ratio);
                                
        if( !living(ob) ) return 0;
// if enable parry as weapon but no weapon  then set no_parry skill
        if ( skill == "no_parry") level = ob->query_skill("parry",1)/2;
        else level = ob->query_skill(skill);

        switch(usage) {
                case SKILL_USAGE_ATTACK:
                        level += ob->query_temp("apply/attack");
// for action["attack"] cmy
//                      CHANNEL_D->do_channel(ob,"sys",sprintf("origin:%d,add %d " , level,ob->query_temp("fighting/attack")));
                        level = level * (100 + ob->query_temp("fighting/attack")) / 100;
//                      CHANNEL_D->do_channel(ob,"sys",skill+ sprintf(" after:%d " , level));
                        
                        break;
                case SKILL_USAGE_DEFENSE:
                        level += ob->query_temp("apply/defense");
// for action["dodge"] cmy
                        if (ob->is_fighting()) {
//                      CHANNEL_D->do_channel(ob,"sys",sprintf("%s origin:%d,add %d ", skill,level,ob->query_temp("fighting/"+skill)));
                            if( skill == "dodge") {
                                  int tmp = ob->query_temp("apply/dodge");
                                  if( tmp > 30 ) tmp = 30;
                                  level += tmp;
                                  if( stringp(map_skill= (ob->query_skill_mapped(skill))) && ( eff_level = SKILL_D(map_skill)->effective_level()) > 0) {
                                          level = level * eff_level / 10;       
//                      CHANNEL_D->do_channel(ob,"sys", sprintf(" dodge eff_level:%d " , eff_level));
                                        }
                                  level = level * (100 + ob->query_temp("fighting/dodge")) / 100;
                                }
                                else /*if( skill == "parry")*/
                                {
                                  int tmp = ob->query_temp("apply/parry");
                                  if( tmp > 30) tmp = 30;
                                  level += tmp;
                                  if( stringp(map_skill= (ob->query_skill_mapped(skill))) && ( eff_level = SKILL_D(map_skill)->effective_level()) > 0) 
                                          level = level * eff_level / 10;       
                                  level = level * (100 + ob->query_temp("fighting/parry")) / 100;
                                }
//                      CHANNEL_D->do_channel(ob,"sys",skill+ sprintf(" after:%d " , level));
                        }

                        break;
    }

        if( !level ) return (int)ob->query("combat_exp") / 2;

        power = (level*level*level) / 3;

//if set attack 100,then ap*=2 and dp = 0
//if set attack 0,then ap = 0 and dp*=2
	
	power = (power + ob->query("combat_exp")*2)/50;
	
	gin_ratio = 100;
	sen_ratio = 100;
	//神影响攻击，精影响防御
        if( (status = ob->query("max_sen")) > 0 && power > 1000 )	
        	sen_ratio = 100 * ob->query("sen") / status;
        if( (status = ob->query("max_gin")) > 0 && power > 1000 )	
        	gin_ratio = 100 * ob->query("gin") / status;
        	
        if(gin_ratio < 50 )
        	gin_ratio = 50;
        if(sen_ratio < 50 )
        	sen_ratio = 50;

	//允许部分超常发挥的情况        
        if(gin_ratio > 120 )
        	gin_ratio = 120;
        if(sen_ratio > 120 )
        	sen_ratio = 120;
        
        	
        if( usage == SKILL_USAGE_ATTACK)
		        power = power*a_d_ratio/100*sen_ratio;
        else
        	if( usage == SKILL_USAGE_DEFENSE)                
	        	power = power*(100-a_d_ratio)/100*gin_ratio;

	afford = (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance();
	//负重(>10%)影响攻击与躲闪
	if( afford > 10 && (skill == "dodge" || usage == SKILL_USAGE_ATTACK) )
		power -= power/100*afford;

	if( power < 100 )
		power = 100;
		
	return power;	        	
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type,mapping self_attack_action,object controler)
{
        mapping my, your, action;
        string limb, *limbs, result,str,*armor_key;
        string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill, absorb_skill;
        mixed foo,foo2;       
        object shield;
        mapping armor;

        if( !objectp(me) || !objectp(victim) ) return 0;
        
        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();

        // from xkx cmy 971020
        // (0) Choose skills.
        //


        prepare = me->query_skill_prepare();
        if (!prepare) prepare = ([]);

        if( me->query_temp("action_flag") == 0 ) me->add_temp("action_flag", 1);
        else me->add_temp("action_flag", -1);

        if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
        else if ( sizeof(prepare) == 0) attack_skill = "unarmed";
        else if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
        else if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];

//        CHANNEL_D->do_channel(this_object(), "sys", sprintf("attack_skill:%s\n",attack_skill));



        //
        // (1) Find out what action the offenser will take.
        //
// copy from cmy 971020
        me->reset_action();
// modified by yeung
        
        if(attack_type != TYPE_SELFATTACK) 
        {
                action = me->query("actions");
                if( !mapp(action) ) {
//                  CHANNEL_D->do_channel(this_object(), "sys", sprintf("%O\n", action));
                        me->reset_action();
                        action = me->query("actions");
                        if( !mapp(action) ) {
                                CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s): bad action = %O", me->name(1), me->query("id"), action));
                        return 0;
                        }
                }
                result = "\n" + action["action"] + "！\n";
        }
        else
        {       
                action = self_attack_action;
                result = "";
        }

        //
        // (2) Prepare AP, DP for checking if hit.
        //
// commented by cmy for attack_skill compute before 971020
//      if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
//      else                                    attack_skill = "unarmed";

    limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];
// for action["attack"]       cmy
        me->delete_temp("fighting/attack");
        if (intp(action["attack"]))
                me->set_temp("fighting/attack",action["attack"]);
        ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;
// for action["dodge"]  cmy
                me->delete_temp("fighting/dodge");
                me->delete_temp("fighting/parry");
//      CHANNEL_D->do_channel(me,"sys",sprintf("action:%d ", action["dodge"] ));
        if (intp(action["dodge"]))
                me->set_temp("fighting/dodge", action["dodge"]);
        if (intp(action["parry"]))
                me->set_temp("fighting/parry", action["parry"]);
//      CHANNEL_D->do_channel(me,"sys",sprintf("add attack:%d ", me->query_temp("fighting/attack")));
//      CHANNEL_D->do_channel(me,"sys",sprintf("add dodge:%d ", me->query_temp("fighting/dodge")));
//      CHANNEL_D->do_channel(me,"sys",sprintf("add parry:%d ", me->query_temp("fighting/parry")));


        if( arrayp(me->query_temp("ally/partner")) )
      {
	        object *obj=me->query_temp("ally/partner");
                if( !stringp(me->query_skill_mapped(attack_skill)) || 
                        !SKILL_D(me->query_skill_mapped(attack_skill))->
                        query_ally(obj[0]->query_skill_mapped("parry"),sizeof(obj)+1) )
                {
                        me->remove_all_enemy();
                        return 0;
                }
        }

        coefficient = (int)me->query_temp("ally/coefficient");
        if(coefficient > 100) ap = ap/100*coefficient;
        if( ap < 1 ) ap = 1;

        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( dp < 1 ) dp = 1;

        if( objectp(foo = victim->query_charge_target())
        &&      (foo != me) )
                dp = dp * 2 / 3;
        
        //对看不见的对手,防御和自己的听风辨器术有关.
        if( !victim->visible(me) )
	{
                dp = dp/10*(5+((int)victim->query_skill("perception",1))/30);
        }

        if( victim->is_busy() ) dp /= 3;
        if( dp < 1 ) dp = 1;


        //
        // (3) Fight!
        //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
        //     AP and DP are greater than zero, so we always have chance to hit
        //     or be hit.
        //
//我把combat中的消息分为两步显示。
//先显示攻击者的消息，然后在显示结果。这样在skill中的message_vision就不会在战斗信息之前就先出现了。
//比如quihua-shengong.
//战斗后要显示的信息可以在skill中的后效函数中定义。现在就可以在出招前，战斗中，结束后均能正确显示信息。
//          yeung       
        result = replace_string( result, "$l", limb );
        if( victim->query_temp("weapon"))
                result = replace_string( result, "$v", victim->query_temp("weapon")->name() );
        if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
        else if( stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );
        else if( attack_skill == "finger" )
                result = replace_string( result, "$w", "手指" );
        else if( attack_skill == "strike" )
                result = replace_string( result, "$w", "手掌" );
        else result = replace_string( result, "$w", "拳头" );

        message_combat(1,result, me, victim );
        result = "";

        if( (me != victim) && (random(ap+dp)<dp) && random(action["undodgeable"])<10) {               // Does the victim dodge this hit?
//      only for mudos under win95. random()'s bug.
//      if( (me != victim) && (random((ap+dp)/dp*100) < 100) && (ap/dp)<50 ) {          // Does the victim dodge this hit?

                dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

                if( dp < ap && (!userp(victim) || !userp(me)) 
                &&      random(your["gin"]*100/your["max_gin"] + your["int"]) > 50 ) {
                        your["combat_exp"] += 1;
	                    victim->improve_skill("dodge", 1);
                }

                // This is for NPC only. NPC have chance to get exp when fail to hit.
                if( (ap < dp) && !userp(me) ) {
                        if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
                        me->improve_skill(attack_skill, random(my["int"]));
                }
                damage = RESULT_DODGE;

        } else {

                //
                //      (4) Check if the partner can parry this attack.
                //
                if( arrayp(victim->query_temp("ally/partner")) )
                        partner_ob=victim->query_temp("ally/partner");
                else
                        partner_ob=({});                
                partner_ob += ({victim});
                partner=partner_ob[random(sizeof(partner_ob))];
//added by yeung for debug
//                      partner = victim;

//              if( partner->query_temp("weapon") ) {
                        pp = skill_power(partner, "parry", SKILL_USAGE_DEFENSE);

                        parry_skill = partner->query_skill_mapped("parry");
                        if( !parry_skill ) parry_skill = "parry";
                        coefficient = (int)SKILL_D(parry_skill)->query_sheng_ke(me->query_skill_mapped(attack_skill));
                        if( coefficient > 100 )  pp = pp*coefficient/100;
                        if( coefficient < -100 ) pp = pp*100/(-coefficient);

//                      if( !weapon ) pp *= 2;
/*              } else {
//                      if( weapon ) pp = 0;
//                      else pp = skill_power(partner, "unarmed", SKILL_USAGE_DEFENSE);
                        prepare = partner->query_skill_prepare();
                        if (!prepare) prepare = ([]);
                        if ( sizeof(prepare) == 0) parry_skill = "parry";
                        else  parry_skill = (keys(prepare))[0];

                        if( stringp(partner->query_skill_mapped(parry_skill)) && 
                                SKILL_D(partner->query_skill_mapped(parry_skill))->valid_enable("parry") )
                        {
                                parry_skill = partner->query_skill_mapped(parry_skill);
	                            pp = skill_power(partner,parry_skill, SKILL_USAGE_DEFENSE);

                                coefficient = (int)SKILL_D(parry_skill)->query_sheng_ke(me->query_skill_mapped(attack_skill));
                                if( coefficient > 100 )  pp = pp*coefficient/100;
                                if( coefficient < -100 ) pp = pp*100/(-coefficient);
                        }
                        else
                        {
                                pp = skill_power(partner, "no_parry", SKILL_USAGE_DEFENSE);
                                parry_skill = "parry";
                        }
//                      if( weapon ) pp /= 2;
                }
*/
                if( partner->is_busy() ) pp /= 3;
                if( pp < 1 ) pp = 1;

                coefficient = (int)partner->query_temp("ally/coefficient");
                if(coefficient > 100) pp = pp/100*coefficient;

                //对看不见的对手,防御和自己的听风辨器术有关.
                if( !victim->visible(me) )
                {
	                  pp = pp/10*(5+((int)victim->query_skill("perception",1))/30);
                }

                if( pp < 1 ) pp = 1;

// self-attack cannot be parryed
        if( (victim != me) && (random(ap+pp)<pp) && random(action["unparryable"])<10 ) {               // Does the victim dodge this hit?
//      only for mudos under win95. random()'s bug.
//      if( (victim != me) && (random((ap+pp)/pp*100) < 100) && (ap/pp)<50 ) {          // Does the victim dodge this hit?


//                      parry_skill = partner->query_skill_mapped("parry");
//                      if( !parry_skill ) parry_skill = "parry";
                        // change to SKILL_D(parry_skill) after added parry msg to those
                        // martial arts that can parry.
// modified by yeung
                        str = SKILL_D(parry_skill)->query_parry_msg(partner->query_temp("weapon"),partner,me,action);
//                      CHANNEL_D->do_channel(victim,"sys",sprintf("%s:msg:%s\n",parry_skill,str));
//                      CHANNEL_D->do_channel(victim,"sys",sprintf("ok"));
                        if(partner != victim && attack_type != TYPE_SELFATTACK)
                        {
                                str = replace_string(str, "$n", partner->name());
                                if( partner->query_temp("weapon"))
                                      str = replace_string( str, "$v",
                                                 partner->query_temp("weapon")->name() );
                                str=HIY ""+str+"" NOR;
// 当攻击被转移的时候会产生错误。所以先注掉这一行。
//                              result += HIY "但是"+partner->name()+"接住了"+me->name()+"的攻势。\n"NOR;
                                if( userp(me) )
                                {
                                        partner->add("combat_exp",1);
                                        partner->improve_skill("parry", 1);
                                }
                        }
                        else
                        {
                                if( dp < ap && (!userp(victim) || !userp(me)) 
                                &&      random(your["gin"]*100/your["max_gin"] + your["int"]) > 50 ) {
                                        your["combat_exp"] += 1;
                                        victim->improve_skill("parry", 1);
                                }
                        }

                        result += str;
                        damage = RESULT_PARRY;

	            } else {

                        //
                        //      (5) We hit the victim and the victim failed to parry
                        //
                        damage = me->query_temp("apply/damage");
                        damage = (damage + random(damage)) / 2;
                        if( action["damage"] )
                                damage += action["damage"] * damage / 100;

                        damage_bonus = me->query_str();

                        // Let force skill take effect.
                        if( my["force_factor"] && (my["force"] > my["force_factor"]) ) {
                                if( force_skill = me->query_skill_mapped("force") ) {
                                        foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
                                        if( stringp(foo) ) result += foo;
                                        else if( intp(foo) ) {
                                                damage_bonus += foo;
// for action["force"] cmy 
//                      CHANNEL_D->do_channel(this_player(),"sys",sprintf("origin damage:%d foo:%d" ,damage_bonus,foo));
                        if( action["force"] )
                                damage_bonus += action["force"] * foo / 200;
//                  CHANNEL_D->do_channel(this_player(),"sys",sprintf("after damage:%d " , damage_bonus));
                                        }
                                }
                        }

                        if( martial_skill = me->query_skill_mapped(attack_skill) ) {


                                foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);

                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        // Let weapon or monster have their special damage.
                        if( weapon ) {
                                foo = weapon->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo/2;
                        } else {
                                foo = me->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        if( damage_bonus > 0 )
                                damage += (damage_bonus + random(damage_bonus))/2;
                        if( damage < 0 ) damage = 0;

                        // Let combat exp take effect
                        defense_factor = your["combat_exp"];
                        while( random(defense_factor) > my["combat_exp"] ) {
                                damage -= damage / 3;
                                defense_factor /= 2;
                        }
                        
			//加入防具所具有的效果
                        //added by YEUNG 
                        if( mapp( armor = victim->query_temp("armor")) )
                        {     
				armor_key = keys(armor);
				defense_factor = sizeof(armor_key);
				while(defense_factor--)
				{
		                        if( objectp(shield = armor[armor_key[defense_factor]]) )
        		                {
                		        	if( (foo=shield->dispersion_damage(me,victim,damage)) != 0 )
                        			{
							damage -= foo;		
	                        		}	
	        	                }	
	        	         }
			}                        
                                  
                        if( damage < 0 ) damage = 0;
                        
                        
                        
                        
                        
                        
			//added to increase jin-gang by PAFF 
                        //
                        //      (5.5) Check if victim can absorb the damage
                        //
                                absorb_vic = victim->query_skill("iron-cloth")/2;
                                if( victim->query_skill("iron-cloth"))
                                {
                absorb_skill = victim->query_skill_mapped("iron-cloth");
                if( !absorb_skill ) absorb_skill = "iron-cloth";
                result += SKILL_D(absorb_skill)->query_absorb_msg();

                                }
                        //      absorb_me = me->query_skill("iron-cloth")/2;
                                damage_bonus = me->query_skill("iron-cloth")/2;
                                bounce = 0;
                                if( (damage - absorb_vic) < 0 )
                                {
                                absorb_skill = victim->query_skill_mapped("iron-cloth");
                                if( absorb_skill)
                                bounce = 0 - ((SKILL_D(absorb_skill)->bounce_ratio()) * (damage - absorb_vic) / 10);
                                else
                                bounce = 0;
                                absorb_skill = me ->query_skill_mapped("iron-cloth");
                               if( absorb_skill)
                                bounce -= (SKILL_D(absorb_skill)->bounce_ratio()) * damage_bonus / 10;
                                else
                                bounce -= 0;
                                if ( bounce < 0 ) bounce = 0;
                        me->receive_damage("kee", bounce, victim );
                        result += damage_msg(bounce, "反弹伤");
                                }
                                else
                                {
                        // let iron_cloth relieve damage ;dao
                                damage -= absorb_vic;

                        // (5.6) if use taiji then relieve damage 
                        // 
                                {
                                force_skill = victim->query_skill_mapped("force");
                                if(damage > 0 && force_skill &&  foo = (int) SKILL_D(force_skill)->query_relieve_coff()) {
                        // foo relieve_coff , foo2 force_skill
                                    foo2 = (int)victim->query_skill("force");
                                    if( foo2 > 500) foo2 = 500;
                                    if( foo >= 90 ) foo = 90;
//                      CHANNEL_D->do_channel( this_object(), "sys", sprintf("damage after absorb %d", damage));
                                    damage -= damage * foo2 * foo/50000;        
//                      CHANNEL_D->do_channel( this_object(), "sys", sprintf("damage after releive %d", damage));
                                    result+=SKILL_D(force_skill)->query_relieve_message();
                                   }
                                }                               
                        
                        //
                        //      (6) Inflict the damage.
                        //

			
                      damaged = victim->receive_damage("kee", damage, me );

                        if( (me->is_killing(victim) || weapon || my["force_factor"]>100)
                        && random(damage) > (int)victim->query_temp("apply/armor") ) {
                                // We are sure that damage is greater than victim's armor here.
                                wounded = victim->receive_wound("kee",
                                        damage - (int)victim->query_temp("apply/armor"), me);
                        }
                      else
                    wounded = 0;

                        if( objectp(controler) )
                                victim->set_temp("last_damage_from",controler);         

                        result += damage_msg( (damaged > wounded) ? damaged : wounded, action["damage_type"]);

                               }

                        //
                        //      (7) Give experience
                        //

                        if( !userp(me) || !userp(victim) ) {
                                if( (ap < dp)
                                &&   (random(my["gin"]*100/my["max_gin"] + my["int"]) > 30) ) {
                                        my["combat_exp"] += 1;
                                        if( my["potential"] - my["learned_points"] < 300 )
                                                my["potential"] += 1;
                                        me->improve_skill(attack_skill, 1);
                                }
                                if( random(your["max_kee"] + your["kee"]) < damage ) {
                                        your["combat_exp"] += 1;
                                        if( your["potential"] - your["learned_points"] < 300 )
                                                your["potential"] += 1;
                                }
                        }
                }
        } 

        result = replace_string( result, "$l", limb );
// added by PAFF to replace $z of jin-gang skills
        if( victim->query_skill_mapped("iron-cloth"))
                  result = replace_string( result, "$z",  to_chinese(victim->query_skill_mapped("iron-cloth")));

        if( victim->query_temp("weapon"))
        result = replace_string( result, "$v", victim->query_temp("weapon")->name() );

            if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
        else if( stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );
        else if( attack_skill == "finger" )
                result = replace_string( result, "$w", "手指" );
        else if( attack_skill == "strike" )
                result = replace_string( result, "$w", "手掌" );
        else result = replace_string( result, "$w", "拳头" );

        message_combat(1,result, me, victim );

        if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
                if( damage > 0 )
                        tell_object(me, sprintf( GRN "AP：%d，DP：%d，PP：%d，伤害力：%d/%d\n" NOR,
                                ap/100, dp/100, pp/100, damaged, wounded));
                else
                        tell_object(me, sprintf( GRN "AP：%d，DP：%d，PP：%d\n" NOR,
                                ap/100, dp/100, pp/100));
        }

// cmy 971027 ; fight until < 60%
        
    if( (damage > 0) && (damaged || wounded) ) {
//              report_status(victim, wounded);

                if ( bounce > 0)  report_status(victim,me,0);   
                else              report_status(me,victim,(damaged>(wounded+damaged/2)) ? 0 : 1); 
                
                if( victim->is_busy() ) victim->interrupt_me(me, "hit");

// added by yeung
// to let controler deal with victim,if there is controler.
                if( attack_type == TYPE_SELFATTACK && objectp(controler) )
                        me = controler;

                if( (!me->is_killing(victim)) && (!victim->is_killing(me->query("id"))) 
 && ((int)victim->query("kee")*100 / (int)victim->query("max_kee") <= 60 ) ) {
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
                        message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
                        winner_task(me,victim);
                }
// see if the weapon has poison
        if (weapon && weapon->query("poison")) {
// foo poison_add, foo2 poison_type
           foo = (int) weapon->query("poison/amount");
           foo2 = (string) weapon->query("poison/type");
           if ( foo > 10 ) {
                weapon->set("poison/amount", foo - 10);
                foo = 10;
           }
           else weapon->set("poison",0);
        
           tell_object(victim, "你感觉到伤口有些麻木 ...... \n");
          
           if (!victim->query_condition(foo2))
                   victim->apply_condition(foo2, foo);
           else
              victim->apply_condition(foo2, victim->query_condition(foo2)+foo);
// let 中毒者 kill me
        if( !userp(victim))  victim->kill_ob(me);
        }
}

        if( functionp(action["post_action"]) )
                evaluate( action["post_action"], me, victim, weapon, damage);

        // See if the victim can make a riposte.
        if( attack_type==TYPE_REGULAR) { 
          if ( damage < 1
          && victim->query_temp("guarding") 
          && ( victim->visible(me) || (random((int)your["combat_exp"] / 5000 + (int)victim->query_skill("perception")*10) > (int)my["combat_exp"]/ 5000) )
        // counterattack based on cor and exp
          && ( random( (int)me->query_cps()*2 ) < ((int)victim->query("cor") + (int)your["bellicosity"] / 500))
             ) {

                victim->set_temp("guarding", 0);
                message_combat(2,"$N一击不中，露出了破绽！\n", me);
                do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);

        // let dugu-jiujian always counterattack #### not complete
        } else  if (     !victim->is_busy()
        		 && victim->query("kee") > 0
                         && objectp(foo = victim->query_temp("weapon"))
                         &&  ( foo2 = (string) victim->query_skill_mapped(foo->query("skill_type")) ) 
                         &&  (random(SKILL_D(foo2)->counter_attack_ratio()) > 10 ) ) {
                         message_combat(2,"$N看出了$n招式中露出破绽，趁势发动攻击！\n", victim, me);
                         do_attack(victim,me, victim->query_temp("weapon"), TYPE_QUICK);
          }
        }
        if( objectp(me) )
                me->check_status();
        if( objectp(victim) )
                victim->check_status();
}

//      fight()
//
//      This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
int fight(object me, object victim)
{
        object ob;
        string weapon,skill_type,skill_mapped,per_msg;
        int rate,per_lev,per_power,victim_exp;

        //write(me->name(1)+" is fighting.\n");
        if( !objectp(me) || !objectp(victim) ) return 0;
        
        if( !living(me) ) return 1;
    
        per_lev = (int)me->query_skill("perception",1);
        per_power = per_lev*per_lev*per_lev;
        victim_exp = (int)victim->query("combat_exp");
        //write(me->query("id")+"'s per_power "+per_power+" victim_exp "+victim_exp+"\n");
        
        if( !me->visible(victim) )
        {
        //      write(me->query("id")+" cannot see enemy.\n");
                per_power = random(per_power);
                //CHANNEL_D->do_channel(me,"sys",sprintf("per_power %d victim_exp %d",per_power,victim_exp));
                if(per_power<victim_exp/4)
                {
//                      write(me->query("id")+"'s per_power "+per_power+"victim_exp "+victim_exp+"\n");
                        if( per_power>victim_exp/8 )
                                message_vision(GRN"\n$N身形凝立不动，侧耳倾听。\n"NOR,me);
                        me->set_temp("guarding", 1);                            
                        return 0;
                }
                
        }
        
        //write(me->query("id")+" is decideing whether to attack.\n");
        
        per_msg = YEL"\n$N从$n衣袂带风声中感应出$n身形所在，趁势发动攻击！\n"NOR;       
        
        // If victim is busy or unconcious, always take the chance to make an attack.
        if( victim->is_busy() || !living(victim) ) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                if( !me->visible(victim) ) message_vision(per_msg,me,victim);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                return 1;
        // Else, see if we are brave enough to make an aggressive action.
        } else if( random( (int)victim->query("cps") * 2 ) < ((int)me->query("cor") + (int)me->query("bellicosity") / 500) ) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                if( !me->visible(victim) ) message_vision(per_msg,me,victim);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
        // for prepared skills attack two times
                if( !objectp(me) || !objectp(victim) ) return 1;
                if( me->is_fighting(victim) && victim->is_fighting(me)) {
                        if( (!objectp(me->query_temp("weapon"))
                           && sizeof(me->query_skill_prepare()) > 1))
                      {
//                      if( me->query_temp("action_flag") == 0 ) me->add_temp("action_flag", 1);
    //                  else me->add_temp("action_flag", -1);
                           do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
//                      me->set_temp("action_flag",0);
                       }
                }
                return 1;
        }
        // see if some skill can attack fast( attack_rate )
        else if ( objectp(weapon = (me->query_temp("weapon")))  
                         && stringp(skill_type = weapon->query("skill_type"))
                         && stringp(skill_mapped = me->query_skill_mapped(skill_type))  
                         && (random(SKILL_D(skill_mapped)->attack_ratio())>10) ) {
                         if( !me->visible(victim) ) message_vision(per_msg,me,victim);
                         do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
                         return 1;
        // Else, we just start guarding.
        } else if( !me->query_temp("guarding") && me->visible(victim) ) {
                me->set_temp("guarding", 1);
                message_combat(3,guard_msg[random(sizeof(guard_msg))], me, victim);
                return 0;
        } else return 0;
}

    //  auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
        // Don't let NPC autofight NPC.
        if( !userp(me) && !userp(obj) ) return;
        if( userp(me) && userp(obj) ) return;
        
        // Because most of the cases that we cannot start a fight cannot be checked
        // before we really call the kill_ob(), so we just make sure we have no 
        // aggressive callout wating here.
        if( me->query_temp("looking_for_trouble") ) return;
        me->set_temp("looking_for_trouble", 1);

        // This call_out gives victim a chance to slip trough the fierce guys.
        call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
        int bellicosity;

        if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        bellicosity = (int)me->query("bellicosity");
        message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);

        if(     (int)me->query("force") > (random(bellicosity) + bellicosity)/2 ) return;

        if( bellicosity > (int)me->query("score") 
        &&      !wizardp(obj) ) {
                message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me)
                        + "看你实在很不顺眼，去死吧。\n", me, obj);
                me->kill_ob(obj);
        } else {
                message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj)
                        + "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",
                        me, obj);
                me->fight_ob(obj);
        }
}

void start_hatred(object me, object obj)
{
        if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        ||      me->query("pkquest/victimid")==obj->query("id")
        ||      me->query("id")==obj->query("pkquest/victimid") //Are we in pk?
        )       return;

        // We found our hatred! Charge!
        message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
        me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
        if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        // We found our vendetta opponent! Charge!
        me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
        if( !me || !obj ) return;                               // Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            // Are we busy fighting?
        ||      !living(me)                                                     // Are we capable for a fight?
        ||      environment(me)!=environment(obj)       // Are we still in the same room?
        ||      environment(me)->query("no_fight")      // Are we in a peace room?
        )       return;

        // We got a nice victim! Kill him/her/it!!!
        me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
        switch(event) {
                case "dead":
                        message_vision("\n$N死了。\n\n", ob);
                        break;
                case "unconcious":
                        message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
                        break;
                case "revive":
                        message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n", ob);
                        break;
        }
}

void winner_reward(object killer, object victim)
{
        killer->defeated_enemy(victim);
        if(! killer->is_killing(victim->query("id")))
        {
                winner_task(killer,victim);
        }
}

// modified by yeung to punish PKer 99/02/01
void killer_reward(object killer, object victim)
{
        int bls;
        string vmark;
        string adv_force;
        mapping quest;
        int pk_flag = 0,force_punish,exp_punish,faith_punish,skill_punish,factor;
        int atman_punish,mana_punish;

        // Call the mudlib killer apply.
        killer->killed_enemy(victim);
        

        if( userp(victim) ) {
                killer->add("PKS", 1);
//                CHANNEL_D->do_channel(killer,"sys", sprintf( "%s,%s,%d\n",killer->query("pker_name"),victim->name(),killer->query("pker_name")==victim->name()));
// ADDED BY PAFF 1997 11 29 to punish pker 
/*                if(!killer->query_temp("killed") || !(killer->query("pker_name")==victim->name())){
                    killer->add("PKERS",1); 
                    if( killer->query("PKERS") < 5 ) 
                      tell_object(killer,"罪过，罪过，你手上又多了一条人命\n");
                    else{
                      if ( killer->query("PKERS") < 10 )
                         tell_object(killer,"你已经血债累累了，小心报应啊\n");
                      else
                         pkers_punish(killer);
                    }
                   }
                    else {
                      killer->delete_temp("killed");
                          killer->delete("pker_name");
                    }
*/

                // 对pk仇杀进行特殊处理       yeung
                if( userp(killer) && userp(victim) && killer->query_temp("pk_id") 
                        && member_array(victim->query("id"),killer->query_temp("pk_id"))!=-1 )
                {
/*
                        int pk_point;

                        killer->set_temp("pk_id",killer->query_temp("pk_id")-({victim->query("id")}) );

                        pk_point = 100*killer->query("combat_exp")/(victim->query("combat_exp")+1);
                        if( interactive(killer)
                                 &&  killer->query("pkquest/victimid")==victim->query("id")
                                 &&  userp(victim) )
                        {
                                pk_point /= 10;
                        }
                        pk_point = pk_point*(killer->query("pk_point")+1)/(victim->query("pk_point")+1);
                        if( pk_point > 500 ) pk_point = 500;
                        killer->add("pk_point",pk_point); 
    */                  
/*
                        //计算惩罚系数
                        factor = killer->query("combat_exp")/victim->query("combat_exp")*3;
                        //系数不会超过 3或1/3
                        if( factor > 9 ) factor = 9;
                        if( factor < 1 ) factor = 1;
                        //根据死者的pks来决定死者死亡惩罚程度
                        pk_flag = victim->query("PKS");         
                        //根据死者的pks来决定凶手的惩罚程度
                        factor /= (victim->query("PKS")+1);     
                        //计算惩罚数值
*/
                        force_punish = killer->query("max_force")/100;
                        if( force_punish < 30 ) force_punish = 30;
                        
                        mana_punish = killer->query("max_mana")/100;
                        if( mana_punish < 10 ) mana_punish = 10;
                        
                        atman_punish = killer->query("max_atman")/100;
                        if( atman_punish < 10 ) atman_punish = 10;
                        
                        exp_punish = killer->query("combat_exp")/100*5;
                        if( exp_punish < 10000 ) exp_punish = 10000;
                        
                        skill_punish = 1;

                        faith_punish = 200;
                        //同门相残？
                        if( victim->query("faith") > 0 && killer->query("family/family_name") == victim->query("family/family_name") )
                                faith_punish += victim->query("faith");
/* 
                        //确定惩罚程度
                        force_punish *= factor;
                        force_punish /= 3;
                        mana_punish *= factor;
                        mana_punish /= 3;
                        atman_punish *= factor;
                        atman_punish /= 3;
                        exp_punish *= factor;
                        exp_punish /= 3;
                        //faith_punish *= factor;
                        //faith_punish /= 3;
                        //skill_punish *= factor;

*/
                        pk_flag = 2;
                        
                        //进行惩罚                              
                        killer->set("force",0);
                        killer->set("mana",0);
                        killer->set("atman",0);

                        if( killer->query("max_force") > force_punish )
                                killer->add("max_force", -force_punish);
                        else 
                                killer->set("max_force",1);
                        
                        if( killer->query("max_atman") > atman_punish )
                                killer->add("max_atman", -atman_punish);
                        else 
                                killer->set("max_atman",1);

                        if( killer->query("max_mana") > mana_punish )
                                killer->add("max_mana", -mana_punish);
                        else 
                                killer->set("max_mana",1);

                        if( killer->query("combat_exp") > exp_punish )
                                killer->add("combat_exp", -exp_punish);
                        else 
                                killer->set("combat_exp",1);
                        
                        killer->add("faith",-faith_punish);

                        //内功惩罚                      
                        killer->set_skill("force",killer->query_skill("force",1)-skill_punish);
                        if( (adv_force = killer->query_skill_mapped("force")) )
                                killer->set_skill(adv_force,killer->query_skill(adv_force,1)-skill_punish);
                        else
                                killer->set_skill("force",killer->query_skill("force",1)-skill_punish);
                                
                        if( killer->query_skill("force",1) <= 0) killer->delete_skill("force");                  
                        if( killer->query_skill(adv_force,1) <= 0) killer->delete_skill(adv_force);

                        //necromancy?   
                        killer->set_skill("spells",killer->query_skill("spells",1)-skill_punish);
                        if( (adv_force = killer->query_skill_mapped("spells")) )
                                killer->set_skill(adv_force,killer->query_skill(adv_force,1)-skill_punish);
                        else
                                killer->set_skill("spells",killer->query_skill("spells",1)-skill_punish);
                                
                        if( killer->query_skill("spells",1) <= 0) killer->delete_skill("spells");                   
                        if( killer->query_skill(adv_force,1) <= 0) killer->delete_skill(adv_force);
        
                        log_file("PK_SUCCESS",sprintf("%s(%s) killed %s(%s) on %s\n",
                                       killer->name(1), geteuid(killer), victim->name(1), geteuid(victim),ctime(time()) ) );

                }
                else 
                        pk_flag = 0;

                if(victim->query_temp("pk_id") 
                        && member_array(killer->query("id"),victim->query_temp("pk_id"))!=-1 )
                {
                        victim->set_temp("pk_id",victim->query_temp("pk_id")-({killer->query("id")}) );
                }

                victim->clear_condition();
                // Give the death penalty to the dying user.
                victim->set("bellicosity", 0);
                victim->add("combat_exp", -(int)victim->query("combat_exp")*5/100*(pk_flag+1) );
                victim->add("shen", -(int)victim->query("shen")*5/100*(pk_flag+1) );
                victim->add("tactic_exp", -(int)victim->query("tactic_exp")*5/100*(pk_flag+1) );
                victim->delete("guan");
                victim->delete("marks/帮派");

                if( stringp(vmark = killer->query("vendetta_mark")) )
                        victim->delete("vendetta/" + vmark);
                if( victim->query("thief") )
                        victim->set("thief", (int)victim->query("thief") / 2);
                if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                        victim->add("potential",
                                ((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );

                victim->skill_death_penalty(pk_flag);

                bls = 10;
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s被%s"+(pk_flag?"谋杀了。":"杀死了。"), victim->name(), killer->name()));
                
        } else {
                if (victim->query("owner") != (string)killer->query("id")) {
                killer->add("MKS", 1); 
                }
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s被%s杀死了。", victim->name(), killer->name()));

                bls = 1;
        }
// for quest reward cmy : 971115
 if( interactive(killer) && (quest = killer->query("quest"))
 && ( (int)killer->query("task_time") >= time())
 && (victim->name() == quest["quest"])
 && (quest["quest_type"] == "杀")
 && !userp(victim)
 && (!killer->query("over_time")))
 {
        killer->set("over_time", time());
}

// for pkquest
 if( interactive(killer)
 &&  killer->query("pkquest/victimid")==victim->query("id")
 &&  userp(victim) )
 {
        killer->set("pkquest/pkdone", 1);
 }

 if( interactive(killer)
 &&  victim->query("pkquest/victimid")==killer->query("id")
     &&  userp(victim) )
 {
        victim->add("pkquest/bekilled", 1);
 }
//for pkquest 

        // NPC got 10 times of bellicosity than user.
        
        // 杀小dummy不增加杀气。
        // 避免有人用dummy去杀npc捣乱，和玩家杀dummy涨杀气。
        // yeung
        if( victim->query("combat_exp") > 10000 || !userp(victim) )     
                killer->add("bellicosity", bls * (userp(killer)? 1: 10));

        environment(killer)->add("resource/apparition", 1);

      //ADDED BY PAFF to set shen after kill 

        if (userp(killer) && (killer->query("combat_exp") < victim->query("combat_exp"))){
                killer->add("shen", -(int)victim->query("shen") / 10);
       }

        if( stringp(vmark = victim->query("vendetta_mark")) )
                killer->add("vendetta/" + vmark, 1);
}

int  winner_task(object me, object victim)
//      add for win task , dao 971128
{
        mapping quest;
        tell_object(me,"你战胜了"+victim->name()+"!\n");
// add for quest win
// for quest reward cmy : 971125
 if( interactive(me) && (quest = me->query("quest"))
 && ( (int)me->query("task_time") >= time())
 && (victim->name() == quest["quest"])
 && (quest["quest_type"] == "胜")
 && !userp(victim)
 && (!me->query("over_time")))
 {
        me->set("over_time", time());
   }
}

int pkers_punish(object me)
{
    /*
  object dest;
  tell_object(me,"你死定了\n");
  dest=new("/d/wizard/npc/anti_pker");
  dest->move("/d/snow/inn");
  dest->set("waiting_target", me->query("id"));
  dest->set("target_name",me->query("name"));
  me->apply_condition("anti_pker",9000);
*/
}

