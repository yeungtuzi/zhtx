// chard.c

#include <race.h>

mapping race_daemon = ([
        "人类": RACE_D("human"),
        "赛亚人": RACE_D("human"),
        "飞禽": RACE_D("bird"),
        "野兽": RACE_D("beast"),
        "不死生物": RACE_D("undead"),
]);

void create() { seteuid(getuid()); }
void setup_char(object ob)
{
        string race;
        mapping my;

        if( !stringp(race = ob->query("race")) ) {
                race = "人类";
                ob->set("race", "人类");
        }

        if( undefinedp(race_daemon[race]) )             
                error("chard: undefined race " + race + ".\n");

        race_daemon[race]->setup(ob);

        my = ob->query_entire_dbase();

        if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
        if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
        if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];

        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];

/* ADDED BY PAFF to set npc's shen */
        if( undefinedp(my["shen_type"]) ) my["shen_type"] = 0;

        if( undefinedp(my["shen"]) ) {
                int sign=1;
                if (userp(ob))
                        my["shen"] = 0;
                else {
                        if(my["shen_type"]>0) sign = 1;
                        else if(my["shen_type"] < 0) sign = -1;
                        else sign= 0;
                        my["shen"] = sign * my["combat_exp"] / 10;
                }
        }
        else {
                if( my["mud_age"] < 86400*2 && my["shen"] > 100000) {
                        my["shen"] = 100000;
                }

        }
// avoid excess force like xkx, Dao 980211
        if (userp(ob)) 
        {
                if (my["max_force"] > (int)ob->query_skill("force",1) * 30)
                        my["max_force"] = ob->query_skill("force",1) * 30;
                if (my["force"] > my["max_force"]*4)
                        my["force"] = my["max_force"]*4;
        }

        if( !ob->query_max_encumbrance() )
                ob->set_max_encumbrance( my["str"] * 5000 );

        ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
        int i, apparition;
        object corpse, *inv;
        string corpse_ob;

        // Ghosts don't leave a corpse.
        if( victim->is_ghost() ) {
                all_inventory(victim)->owner_is_killed(killer);
                inv = all_inventory(victim);
                i = sizeof(inv);
                while(i--) inv[i]->move(environment(victim));
                return 0;
        }

        if( !stringp(corpse_ob = victim->query("corpse_ob")) )
                corpse_ob = CORPSE_OB;
        corpse = new(corpse_ob);
        corpse->set_name( victim->name(1) + "的尸体", ({ "corpse" }) );
        corpse->set("long", victim->long()
                + "然而，" + gender_pronoun(victim->query("gender")) 
                + "已经死了，只剩下一具尸体静静地躺在这里。\n");
        corpse->set("age", victim->query("age"));
        corpse->set("gender", victim->query("gender"));
        corpse->set("victim_name", victim->name(1));
        corpse->set_weight( victim->query_weight() );
        corpse->set_max_encumbrance( victim->query_max_encumbrance() );
        corpse->set("combat_exp",victim->query("combat_exp"));
        corpse->set("max_force",victim->query("max_force"));
        corpse->move(environment(victim));
        
        // Don't let wizard left illegal items in their corpses.
        if( !wizardp(victim) ) {
                all_inventory(victim)->owner_is_killed(killer);
                inv = all_inventory(victim);
                i = sizeof(inv);
                while(i--) {
                        if( (string)inv[i]->query("equipped")=="worn" ) {
                                inv[i]->move(corpse);
                                if( !inv[i]->wear() ) inv[i]->move(environment(victim));
                        }
                        else inv[i]->move(corpse);
                }
        }

        // Some nasty surprise ...
        if( apparition = environment(victim)->query("resource/apparition") ) {
                object wraith;

                //这里限制了只有pk才出现ghost，为了防止有人robot 刷装备
                if( userp(victim) && userp(killer) && random(apparition) >= (int)killer->query("kar") ) {
                        message("vision", "突然一阵阴风吹起 ....\n", environment(victim));
                        wraith = new("/obj/npc/wraith");
                        wraith->move(environment(victim));
                        wraith->set("combat_exp", apparition * 1000 );
                        wraith->set_temp("apply/damage", apparition / 2);
                        wraith->set_temp("apply/attack", apparition / 2);
                        wraith->kill_ob(killer);
                        wraith->set_leader(killer);
                }
        }

        return corpse;
}

