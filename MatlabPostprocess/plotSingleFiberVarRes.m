% Clear workspace
clear all



%% Load result
outFolder = '../Install/bin/';
run([outFolder,'SingleFiberVarRes_output.m'])
run([outFolder,'SingleFiberVarRes_params.m'])




%% Plot result
close all

figure('outerposition',[300,800,750,550])
plot(t,Vlv,t,Vla)
title('Volumes [ml]')
legend('Vlv','Vla')


figure('outerposition',[1055,800,750,550])
plot(t,Plv*7.5, t,Pla*7.5, t,Psa*7.5, t,Psp_fixed*ones(size(t))*7.5, t,Ppv_fixed*ones(size(t))*7.5)
title('Pressures [mmHg]')
legend('Plv','Pla','Psa','Psp(fixed)','Ppv(fixed)')


figure('outerposition',[1055,200,750,550])
plot(t,At_ventricle, t, At_atrium)
title('Activation')
legend('Ventricles', 'Atria')


figure('outerposition',[300,200,750,550])
plot(Vlv,Plv*7.5,Vla,Pla*7.5)
title('PV-loops')
legend('LV', 'LA')

axis([0,max(Vlv)+50,0,max(Plv)*7.5+10])

figure('outerposition',[1850,800,750,550])
plot(t,qmv,t,qaov)
title('q [ml/s]')
legend('qmv','qaov')

























