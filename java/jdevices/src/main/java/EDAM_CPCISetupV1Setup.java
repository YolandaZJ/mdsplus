
import java.awt.Dimension;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * EDAM_CPCISetupV1Setup.java
 *
 * Created on Oct 13, 2009, 1:33:00 PM
 */

/**
 *
 * @author taliercio
 */
public class EDAM_CPCISetupV1Setup extends DeviceSetup {

    /** Creates new form EDAM_CPCISetupV1Setup */
    public EDAM_CPCISetupV1Setup() {
	initComponents();
	pack();
	this.setPreferredSize(new Dimension(200,300));
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

	deviceButtons1 = new DeviceButtons();
	jPanel1 = new javax.swing.JPanel();
	jTabbedPane1 = new javax.swing.JTabbedPane();
	jPanel7 = new javax.swing.JPanel();
	jPanel9 = new javax.swing.JPanel();
	jPanel30 = new javax.swing.JPanel();
	deviceField1 = new DeviceField();
	jPanel31 = new javax.swing.JPanel();
	deviceField2 = new DeviceField();
	jPanel32 = new javax.swing.JPanel();
	deviceField3 = new DeviceField();
	jPanel33 = new javax.swing.JPanel();
	deviceField4 = new DeviceField();
	jPanel34 = new javax.swing.JPanel();
	deviceField5 = new DeviceField();
	jPanel35 = new javax.swing.JPanel();
	deviceField6 = new DeviceField();
	jPanel36 = new javax.swing.JPanel();
	deviceField7 = new DeviceField();
	jPanel37 = new javax.swing.JPanel();
	deviceField8 = new DeviceField();
	jPanel38 = new javax.swing.JPanel();
	deviceField9 = new DeviceField();
	jPanel6 = new javax.swing.JPanel();
	jPanel10 = new javax.swing.JPanel();
	jPanel16 = new javax.swing.JPanel();
	jLabel1 = new javax.swing.JLabel();
	jPanel18 = new javax.swing.JPanel();
	jPanel17 = new javax.swing.JPanel();
	jPanel19 = new javax.swing.JPanel();
	jPanel20 = new javax.swing.JPanel();
	jPanel21 = new javax.swing.JPanel();
	jPanel22 = new javax.swing.JPanel();
	jPanel39 = new javax.swing.JPanel();
	deviceField17 = new DeviceField();
	jPanel40 = new javax.swing.JPanel();
	deviceField18 = new DeviceField();
	jPanel5 = new javax.swing.JPanel();
	jPanel11 = new javax.swing.JPanel();
	jPanel45 = new javax.swing.JPanel();
	deviceField10 = new DeviceField();
	jPanel42 = new javax.swing.JPanel();
	deviceField11 = new DeviceField();
	jPanel43 = new javax.swing.JPanel();
	deviceField12 = new DeviceField();
	jPanel44 = new javax.swing.JPanel();
	deviceField13 = new DeviceField();
	jPanel46 = new javax.swing.JPanel();
	deviceField14 = new DeviceField();
	jPanel47 = new javax.swing.JPanel();
	deviceField15 = new DeviceField();
	jPanel41 = new javax.swing.JPanel();
	deviceField16 = new DeviceField();
	jPanel49 = new javax.swing.JPanel();
	deviceField19 = new DeviceField();
	jPanel48 = new javax.swing.JPanel();
	deviceField20 = new DeviceField();
	jPanel4 = new javax.swing.JPanel();
	jPanel12 = new javax.swing.JPanel();
	jPanel23 = new javax.swing.JPanel();
	jLabel2 = new javax.swing.JLabel();
	jPanel24 = new javax.swing.JPanel();
	jPanel25 = new javax.swing.JPanel();
	jPanel26 = new javax.swing.JPanel();
	jPanel27 = new javax.swing.JPanel();
	jPanel28 = new javax.swing.JPanel();
	jPanel29 = new javax.swing.JPanel();
	jPanel51 = new javax.swing.JPanel();
	deviceField21 = new DeviceField();
	jPanel50 = new javax.swing.JPanel();
	deviceField22 = new DeviceField();
	jPanel3 = new javax.swing.JPanel();
	jPanel13 = new javax.swing.JPanel();
	jPanel52 = new javax.swing.JPanel();
	deviceField23 = new DeviceField();
	jPanel53 = new javax.swing.JPanel();
	deviceField24 = new DeviceField();
	jPanel54 = new javax.swing.JPanel();
	deviceField25 = new DeviceField();
	jPanel55 = new javax.swing.JPanel();
	deviceField26 = new DeviceField();
	jPanel56 = new javax.swing.JPanel();
	deviceField27 = new DeviceField();
	jPanel57 = new javax.swing.JPanel();
	deviceField28 = new DeviceField();
	jPanel58 = new javax.swing.JPanel();
	deviceField29 = new DeviceField();
	jPanel59 = new javax.swing.JPanel();
	deviceField30 = new DeviceField();
	jPanel60 = new javax.swing.JPanel();
	deviceField31 = new DeviceField();
	jPanel8 = new javax.swing.JPanel();
	jPanel15 = new javax.swing.JPanel();
	jPanel64 = new javax.swing.JPanel();
	deviceField34 = new DeviceField();
	jPanel66 = new javax.swing.JPanel();
	deviceField35 = new DeviceField();
	jPanel65 = new javax.swing.JPanel();
	deviceField38 = new DeviceField();

	setDeviceProvider("localhost");
	setDeviceTitle("EDAM CPCI Data Acquisition Setup");
	setDeviceType("EDAM_CPCISetup");
	getContentPane().add(deviceButtons1, java.awt.BorderLayout.PAGE_END);

	jPanel1.setLayout(new java.awt.BorderLayout());

	jPanel7.setLayout(new java.awt.BorderLayout());

	jPanel9.setLayout(new java.awt.GridLayout(9, 0));

	deviceField1.setEditable(false);
	deviceField1.setIdentifier("");
	deviceField1.setLabelString("Trigger Event:");
	deviceField1.setNumCols(25);
	deviceField1.setOffsetNid(37);
	deviceField1.setTextOnly(true);
	jPanel30.add(deviceField1);

	jPanel9.add(jPanel30);

	deviceField2.setIdentifier("");
	deviceField2.setLabelString("Trigger Delay:");
	deviceField2.setNumCols(25);
	deviceField2.setOffsetNid(38);
	jPanel31.add(deviceField2);

	jPanel9.add(jPanel31);

	deviceField3.setEditable(false);
	deviceField3.setIdentifier("");
	deviceField3.setLabelString("DClock Event:");
	deviceField3.setNumCols(25);
	deviceField3.setOffsetNid(37);
	deviceField3.setTextOnly(true);
	jPanel32.add(deviceField3);

	jPanel9.add(jPanel32);

	deviceField4.setIdentifier("");
	deviceField4.setLabelString("DClock Delay:");
	deviceField4.setNumCols(25);
	deviceField4.setOffsetNid(33);
	jPanel33.add(deviceField4);

	jPanel9.add(jPanel33);

	deviceField5.setIdentifier("");
	deviceField5.setLabelString("DClock Duration:");
	deviceField5.setNumCols(25);
	deviceField5.setOffsetNid(34);
	jPanel34.add(deviceField5);

	jPanel9.add(jPanel34);

	deviceField6.setIdentifier("");
	deviceField6.setLabelString("DClock Frequency 1:");
	deviceField6.setNumCols(25);
	deviceField6.setOffsetNid(35);
	jPanel35.add(deviceField6);

	jPanel9.add(jPanel35);

	deviceField7.setIdentifier("");
	deviceField7.setLabelString("DClock Frequency 2:");
	deviceField7.setNumCols(25);
	deviceField7.setOffsetNid(36);
	jPanel36.add(deviceField7);

	jPanel9.add(jPanel36);

	deviceField8.setIdentifier("");
	deviceField8.setLabelString("Start ACQ:");
	deviceField8.setNumCols(25);
	deviceField8.setOffsetNid(39);
	jPanel37.add(deviceField8);

	jPanel9.add(jPanel37);

	deviceField9.setIdentifier("");
	deviceField9.setLabelString("End ACQ:");
	deviceField9.setNumCols(25);
	deviceField9.setOffsetNid(40);
	jPanel38.add(deviceField9);

	jPanel9.add(jPanel38);

	jPanel7.add(jPanel9, java.awt.BorderLayout.CENTER);

	jTabbedPane1.addTab("PBMV", jPanel7);

	jPanel6.setLayout(new java.awt.BorderLayout());

	jPanel10.setLayout(new java.awt.GridLayout(9, 0));

	jLabel1.setText("Trigger and clock are derived from PBMV");
	jPanel16.add(jLabel1);

	jPanel10.add(jPanel16);
	jPanel10.add(jPanel18);
	jPanel10.add(jPanel17);
	jPanel10.add(jPanel19);
	jPanel10.add(jPanel20);
	jPanel10.add(jPanel21);
	jPanel10.add(jPanel22);

	deviceField17.setIdentifier("");
	deviceField17.setLabelString("Start ACQ:");
	deviceField17.setNumCols(25);
	deviceField17.setOffsetNid(19);
	jPanel39.add(deviceField17);

	jPanel10.add(jPanel39);

	deviceField18.setIdentifier("");
	deviceField18.setLabelString("End ACQ:");
	deviceField18.setNumCols(25);
	deviceField18.setOffsetNid(20);
	jPanel40.add(deviceField18);

	jPanel10.add(jPanel40);

	jPanel6.add(jPanel10, java.awt.BorderLayout.CENTER);

	jTabbedPane1.addTab("TBMV", jPanel6);

	jPanel5.setLayout(new java.awt.BorderLayout());

	jPanel11.setLayout(new java.awt.GridLayout(9, 0));

	deviceField10.setEditable(false);
	deviceField10.setIdentifier("");
	deviceField10.setLabelString("Trigger Event:");
	deviceField10.setNumCols(25);
	deviceField10.setOffsetNid(27);
	deviceField10.setTextOnly(true);
	jPanel45.add(deviceField10);

	jPanel11.add(jPanel45);

	deviceField11.setIdentifier("");
	deviceField11.setLabelString("Trigger Delay:");
	deviceField11.setNumCols(25);
	deviceField11.setOffsetNid(28);
	jPanel42.add(deviceField11);

	jPanel11.add(jPanel42);

	deviceField12.setEditable(false);
	deviceField12.setIdentifier("");
	deviceField12.setLabelString("DClock Event:");
	deviceField12.setNumCols(25);
	deviceField12.setOffsetNid(22);
	deviceField12.setTextOnly(true);
	jPanel43.add(deviceField12);

	jPanel11.add(jPanel43);

	deviceField13.setIdentifier("");
	deviceField13.setLabelString("DClock Delay:");
	deviceField13.setNumCols(25);
	deviceField13.setOffsetNid(23);
	jPanel44.add(deviceField13);

	jPanel11.add(jPanel44);

	deviceField14.setIdentifier("");
	deviceField14.setLabelString("DClock Duration:");
	deviceField14.setNumCols(25);
	deviceField14.setOffsetNid(24);
	jPanel46.add(deviceField14);

	jPanel11.add(jPanel46);

	deviceField15.setIdentifier("");
	deviceField15.setLabelString("DClock Frequency 1:");
	deviceField15.setNumCols(25);
	deviceField15.setOffsetNid(25);
	jPanel47.add(deviceField15);

	jPanel11.add(jPanel47);

	deviceField16.setIdentifier("");
	deviceField16.setLabelString("DClock Frequency 2:");
	deviceField16.setNumCols(25);
	deviceField16.setOffsetNid(26);
	jPanel41.add(deviceField16);

	jPanel11.add(jPanel41);

	deviceField19.setIdentifier("");
	deviceField19.setLabelString("Start ACQ:");
	deviceField19.setNumCols(25);
	deviceField19.setOffsetNid(29);
	jPanel49.add(deviceField19);

	jPanel11.add(jPanel49);

	deviceField20.setIdentifier("");
	deviceField20.setLabelString("End ACQ:");
	deviceField20.setNumCols(25);
	deviceField20.setOffsetNid(30);
	jPanel48.add(deviceField20);

	jPanel11.add(jPanel48);

	jPanel5.add(jPanel11, java.awt.BorderLayout.CENTER);

	jTabbedPane1.addTab("PBMC", jPanel5);

	jPanel4.setLayout(new java.awt.BorderLayout());

	jPanel12.setLayout(new java.awt.GridLayout(9, 0));

	jLabel2.setText("Trigger and clock are derived from PBMC");
	jPanel23.add(jLabel2);

	jPanel12.add(jPanel23);
	jPanel12.add(jPanel24);
	jPanel12.add(jPanel25);
	jPanel12.add(jPanel26);
	jPanel12.add(jPanel27);
	jPanel12.add(jPanel28);
	jPanel12.add(jPanel29);

	deviceField21.setIdentifier("");
	deviceField21.setLabelString("Start ACQ:");
	deviceField21.setNumCols(25);
	deviceField21.setOffsetNid(9);
	jPanel51.add(deviceField21);

	jPanel12.add(jPanel51);

	deviceField22.setIdentifier("");
	deviceField22.setLabelString("End ACQ:");
	deviceField22.setNumCols(25);
	deviceField22.setOffsetNid(10);
	jPanel50.add(deviceField22);

	jPanel12.add(jPanel50);

	jPanel4.add(jPanel12, java.awt.BorderLayout.CENTER);

	jTabbedPane1.addTab("TBMC", jPanel4);

	jPanel3.setLayout(new java.awt.BorderLayout());

	jPanel13.setLayout(new java.awt.GridLayout(9, 0));

	deviceField23.setEditable(false);
	deviceField23.setIdentifier("");
	deviceField23.setLabelString("Trigger Event:");
	deviceField23.setNumCols(25);
	deviceField23.setOffsetNid(51);
	deviceField23.setTextOnly(true);
	jPanel52.add(deviceField23);

	jPanel13.add(jPanel52);

	deviceField24.setIdentifier("");
	deviceField24.setLabelString("Trigger Delay:");
	deviceField24.setNumCols(25);
	deviceField24.setOffsetNid(52);
	jPanel53.add(deviceField24);

	jPanel13.add(jPanel53);

	deviceField25.setEditable(false);
	deviceField25.setIdentifier("");
	deviceField25.setLabelString("DClock Event:");
	deviceField25.setNumCols(25);
	deviceField25.setOffsetNid(46);
	deviceField25.setTextOnly(true);
	jPanel54.add(deviceField25);

	jPanel13.add(jPanel54);

	deviceField26.setIdentifier("");
	deviceField26.setLabelString("DClock Delay:");
	deviceField26.setNumCols(25);
	deviceField26.setOffsetNid(47);
	jPanel55.add(deviceField26);

	jPanel13.add(jPanel55);

	deviceField27.setIdentifier("");
	deviceField27.setLabelString("DClock Duration:");
	deviceField27.setNumCols(25);
	deviceField27.setOffsetNid(48);
	jPanel56.add(deviceField27);

	jPanel13.add(jPanel56);

	deviceField28.setIdentifier("");
	deviceField28.setLabelString("DClock Frequency 1:");
	deviceField28.setNumCols(25);
	deviceField28.setOffsetNid(49);
	jPanel57.add(deviceField28);

	jPanel13.add(jPanel57);

	deviceField29.setIdentifier("");
	deviceField29.setLabelString("DClock Frequency 2:");
	deviceField29.setNumCols(25);
	deviceField29.setOffsetNid(50);
	jPanel58.add(deviceField29);

	jPanel13.add(jPanel58);

	deviceField30.setIdentifier("");
	deviceField30.setLabelString("Start ACQ:");
	deviceField30.setNumCols(25);
	deviceField30.setOffsetNid(53);
	jPanel59.add(deviceField30);

	jPanel13.add(jPanel59);

	deviceField31.setIdentifier("");
	deviceField31.setLabelString("End ACQ:");
	deviceField31.setNumCols(25);
	deviceField31.setOffsetNid(54);
	jPanel60.add(deviceField31);

	jPanel13.add(jPanel60);

	jPanel3.add(jPanel13, java.awt.BorderLayout.CENTER);

	jTabbedPane1.addTab("PBV_TBV_FAST", jPanel3);

	jPanel8.setLayout(new java.awt.BorderLayout());

	jPanel15.setLayout(new java.awt.GridLayout(9, 0));

	deviceField34.setEditable(false);
	deviceField34.setIdentifier("");
	deviceField34.setLabelString("Event:");
	deviceField34.setNumCols(25);
	deviceField34.setOffsetNid(42);
	deviceField34.setTextOnly(true);
	jPanel64.add(deviceField34);

	jPanel15.add(jPanel64);

	deviceField35.setIdentifier("");
	deviceField35.setLabelString("Delay:");
	deviceField35.setNumCols(25);
	deviceField35.setOffsetNid(43);
	jPanel66.add(deviceField35);

	jPanel15.add(jPanel66);

	deviceField38.setIdentifier("");
	deviceField38.setLabelString("Duration :");
	deviceField38.setNumCols(25);
	deviceField38.setOffsetNid(44);
	jPanel65.add(deviceField38);

	jPanel15.add(jPanel65);

	jPanel8.add(jPanel15, java.awt.BorderLayout.CENTER);

	jTabbedPane1.addTab("ZERO", jPanel8);

	jPanel1.add(jTabbedPane1, java.awt.BorderLayout.CENTER);

	getContentPane().add(jPanel1, java.awt.BorderLayout.CENTER);
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private DeviceButtons deviceButtons1;
    private DeviceField deviceField1;
    private DeviceField deviceField10;
    private DeviceField deviceField11;
    private DeviceField deviceField12;
    private DeviceField deviceField13;
    private DeviceField deviceField14;
    private DeviceField deviceField15;
    private DeviceField deviceField16;
    private DeviceField deviceField17;
    private DeviceField deviceField18;
    private DeviceField deviceField19;
    private DeviceField deviceField2;
    private DeviceField deviceField20;
    private DeviceField deviceField21;
    private DeviceField deviceField22;
    private DeviceField deviceField23;
    private DeviceField deviceField24;
    private DeviceField deviceField25;
    private DeviceField deviceField26;
    private DeviceField deviceField27;
    private DeviceField deviceField28;
    private DeviceField deviceField29;
    private DeviceField deviceField3;
    private DeviceField deviceField30;
    private DeviceField deviceField31;
    private DeviceField deviceField34;
    private DeviceField deviceField35;
    private DeviceField deviceField38;
    private DeviceField deviceField4;
    private DeviceField deviceField5;
    private DeviceField deviceField6;
    private DeviceField deviceField7;
    private DeviceField deviceField8;
    private DeviceField deviceField9;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel10;
    private javax.swing.JPanel jPanel11;
    private javax.swing.JPanel jPanel12;
    private javax.swing.JPanel jPanel13;
    private javax.swing.JPanel jPanel15;
    private javax.swing.JPanel jPanel16;
    private javax.swing.JPanel jPanel17;
    private javax.swing.JPanel jPanel18;
    private javax.swing.JPanel jPanel19;
    private javax.swing.JPanel jPanel20;
    private javax.swing.JPanel jPanel21;
    private javax.swing.JPanel jPanel22;
    private javax.swing.JPanel jPanel23;
    private javax.swing.JPanel jPanel24;
    private javax.swing.JPanel jPanel25;
    private javax.swing.JPanel jPanel26;
    private javax.swing.JPanel jPanel27;
    private javax.swing.JPanel jPanel28;
    private javax.swing.JPanel jPanel29;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel30;
    private javax.swing.JPanel jPanel31;
    private javax.swing.JPanel jPanel32;
    private javax.swing.JPanel jPanel33;
    private javax.swing.JPanel jPanel34;
    private javax.swing.JPanel jPanel35;
    private javax.swing.JPanel jPanel36;
    private javax.swing.JPanel jPanel37;
    private javax.swing.JPanel jPanel38;
    private javax.swing.JPanel jPanel39;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel40;
    private javax.swing.JPanel jPanel41;
    private javax.swing.JPanel jPanel42;
    private javax.swing.JPanel jPanel43;
    private javax.swing.JPanel jPanel44;
    private javax.swing.JPanel jPanel45;
    private javax.swing.JPanel jPanel46;
    private javax.swing.JPanel jPanel47;
    private javax.swing.JPanel jPanel48;
    private javax.swing.JPanel jPanel49;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel50;
    private javax.swing.JPanel jPanel51;
    private javax.swing.JPanel jPanel52;
    private javax.swing.JPanel jPanel53;
    private javax.swing.JPanel jPanel54;
    private javax.swing.JPanel jPanel55;
    private javax.swing.JPanel jPanel56;
    private javax.swing.JPanel jPanel57;
    private javax.swing.JPanel jPanel58;
    private javax.swing.JPanel jPanel59;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JPanel jPanel60;
    private javax.swing.JPanel jPanel64;
    private javax.swing.JPanel jPanel65;
    private javax.swing.JPanel jPanel66;
    private javax.swing.JPanel jPanel7;
    private javax.swing.JPanel jPanel8;
    private javax.swing.JPanel jPanel9;
    private javax.swing.JTabbedPane jTabbedPane1;
    // End of variables declaration//GEN-END:variables

}
