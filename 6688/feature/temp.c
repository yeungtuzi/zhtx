// attribute.c
// From ES2
// Modified by lysh

#include <dbase.h>
#include <skill.h>


int query_str()
{
        int improve = 0;

        if ( query_skill("unarmed",1) || query_skill("cuff", 1) ||query_skill("hand",1) || query_skill("strike", 1) ||query_skill("finger",1) || query_skill("claw", 1) )
        {
                if ( query_skill("cuff", 1) >= query_skill("unarmed", 1) && query_skill("cuff", 1) >= query_skill("hand", 1) && query_skill("cuff", 1) >= query_skill("strike", 1) && query_skill("cuff", 1) >= query_skill("finger", 1) && query_skill("cuff", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("cuff", 1) / 10;
                else
		if ( query_skill("unarmed", 1) >= query_skill("hand", 1) && query_skill("unarmed", 1) >= query_skill("strike", 1) && query_skill("unarmed", 1) >= query_skill("finger", 1) && query_skill("unarmed", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("unarmed", 1) / 10;
                else
		if ( query_skill("hand", 1) >= query_skill("strike", 1) && query_skill("hand", 1) >= query_skill("finger", 1) && query_skill("hand", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("hand", 1) / 10;
                else
		if ( query_skill("strike", 1) >= query_skill("finger", 1) && query_skill("strike", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("strike", 1) / 10;
                else
		if ( query_skill("finger", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("finger", 1) / 10;
                else
                        improve = (int)query_skill("claw", 1) / 10;
        }

        return (int)query("str") + (int)query("force_factor")/10 +
                query_temp("apply/strength") + improve;
}
int query_int()
{
        return (int)query("int") + query_temp("apply/intelligence") +
                (int)query_skill("literate", 1) / 10;
}

int query_con()
{
        return (int)query("con") + query_temp("apply/constitution") +
                (int)query_skill("force", 1) / 10;
}

int query_dex()
{
        return (int)query("dex") + query_temp("apply/dexerity") +
                (int)query_skill("dodge", 1) / 10;
}
 
int query_kar()
{
	return (int)query("kar")
		+ query_temp("apply/karma")
		- (int)query("MKS") / 300;
}

int query_per()
{
	return (int)query("per")
		+ query_temp("apply/personality");
}
int query_cps()
{
   return (int) query("cps") + (int) query("force_factor")/8 
    - (int) query("bellicosity")/200
		+ (int) query("gift_imp/cps") + query_temp("apply/composure");
}
int query_cor()
{
	int bonus, b;

	bonus = 0;
	b = (int)query("bellicosity") / 20;
	while( (b /= 2) > 0 ) bonus ++;
      if(bonus>20) bonus =20;

	return (int)query("cor") + bonus + query_temp("apply/courage");
}
int query_spi()
{
	return (int)query("spi") + query("gift_imp/spi")
		+ query_temp("apply/spirituality");
}
